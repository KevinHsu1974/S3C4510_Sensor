// --------------------------------------------------------------------
//
//   Title     :  LCD.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  LCD Display HD44780
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
#include "S3C4510_addr.h"

#ifndef LCD_H
#define LCD_H

#ifdef __cplusplus
extern "C" {
#endif

//Set up LCD controller Instruction and Data Register Address; RS = Addr(4), R/W = Addr(3)
#define WriteIR  (*(unsigned char *)(EX_BANK1_BASE)) //RS=0 R/W=0
#define ReadIR   (*(unsigned char *)(EX_BANK1_BASE + (0b01<<3))) //RS=0 R/W=1 
#define WriteDR  (*(unsigned char *)(EX_BANK1_BASE + (0b10<<3))) //RS=1 R/W=0    
#define ReadDR   (*(unsigned char *)(EX_BANK1_BASE + (0b11<<3))) //RS=1 R/W=1 

// LCD controller functions
void LCD_Init();                                      // Function to initialize LCD controller
void Clear_LCD();                                  // Function to clear LCD display
void Check_LCD_Busy();                      // Function to check if LCD is busy
void Write_LCD_Cmd(char cmd);        // Function to write instruction register
void Write_LCD_Data(char Data);       // Function to write date register
void Write_LCD_string (char *fmt,...); // Function to display string 
void GotoXY(int x,int y);                      // Function to assigned display address
void Write_LCD_String (char *fmt,...);

#ifdef __cplusplus
}
#endif

#endif /* LCD_H */

