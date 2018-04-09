// --------------------------------------------------------------------
//
//   Title     :  LCD.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  LCD Controller HD44780 Driver
//             :
//   Limitation:
//             :
//   Note      :
//             :
// --------------------------------------------------------------------
//   modification history :
// --------------------------------------------------------------------
//   Version| mod. date: |
//   V1.0   | 12/15/2017 | Programming start
// --------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "S3C4510_addr.h"
#include "LCD.h"

void LCD_Init() {               
   // Initialize External Bank
   rEXTDBWTH &= 0xff6fffff;    //EXTDBWTH[21:20]=0b00; Disable External I/O bank 0
   usleep(1);
   rEXTDBWTH |= (0x1<<20);     //EXTDBWTH[21:20]=0b01; Set the bus width to "Byte"
   usleep(1);
   
   // Initialize LCD Controller
   Clear_LCD( );                 // Clear Display
   
   // Function Setting
   Write_LCD_Cmd(0x38);          //DL=1:8bits, N=1:Two Rows, F=0:5x7 dot-matrix
   
   // Display on-off control
   Write_LCD_Cmd(0x0d);          //D=1:Display On, C=0:Cursor Off,B=1; Cursor Blinking
 
   // Enter Mode Setting
   Write_LCD_Cmd(0x06);          // I/D=1:Increment By 1, S=0:No Shift
}
void Clear_LCD( ) {             
   Write_LCD_Cmd(0x01);          // Clear Display
}

void Write_LCD_Cmd(char cmd) {
   Check_LCD_Busy();             // Check if LCD is busy
   WriteIR = cmd;                // Write command into Instruction Register
}

void Write_LCD_Data(char data) {
   Check_LCD_Busy();             // Check if LCD is busy
   WriteDR = data;               // write data into Data Register
}

void Write_LCD_String (char *fmt,...) {          // Write string to LCD
        va_list     ap;
        char        string[512], *p=string;

        va_start(ap, fmt);
        vsprintf(string, fmt, ap);
        va_end(ap);
        while (*p)
           Write_LCD_Data(*p++);                // Display character one by one
}

void Check_LCD_Busy() {       // Check if LCD is busy       
   unsigned int BF = 0x1;          
   while(BF)           
   { 
       BF = ReadIR&0x80;       // Check BF flag, Exit loop if BF=0
   }
}

void GotoXY(int x,int y) {    // Move cursor
   char cmd=0x80;              // DB7=1:DD RAM address Setting
   // First Row
   if(y==0) {
      cmd = cmd + 0x00 + x;    // Starting address of first row: 0x00
   }
   // Second Row
   if(y==1) {
      cmd = cmd + 0x40 + x;    // Starting address of second row: 0x40 
   }   
   
   Write_LCD_Cmd(cmd);         // Set DD RAM address to send/receive data
}
