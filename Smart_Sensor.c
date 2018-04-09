// --------------------------------------------------------------------
//
//   Title     :  Smart_Sensor.c 
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  Main function. To display thermal/timing information to LCD, Remote Server or DTE
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
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "S3C4510_addr.h"
#include "Thermal_Read.h"
#include "I2C_RTC.h"
#include "LCD.h"
#include "UART.h"
#include "Remote_Send.h"

unsigned char sec, min, hour, day, month;
double temperature;

int main( int argc, char *argv[] ) {                                   // Format: "SmartSensor 1 xxx:xxx:xxx" or "SmartSensor 2"
   int create_socket, fd;
   /* Initialize peripherals*/
   Thermal_Read_Init();                                                    // Init external bank 1 to read thermal data
   LCD_Init();                                                                      // Init external bank 0 for LCD accessing
   Thermal_Read( &temperature );                                 // Read thermal data (degree in decimal) 
   RTC_Get_Time( &sec, &min, &hour, &day, &month );      // Read the current time information from RTC via I2C
 
   GotoXY(0,0);                                                                 // x=0,y=0: Go to beginning of first row                
   Write_LCD_String("%2d:%2d:2d %2d/%2d", sec, min, hour, day, month);  // Display time information
   GotoXY(0,1);                                                                // x=0,y=1: Go to beginning of second row
   Write_LCD_String("Degree: %5.2f", temperature);    // Display temperature data
   char ch = *argv[1];
   switch (ch) {                                                         // Select option to send the temperature data
       case '1' :
           //int create_socket;
           if ( ( create_socket = socket(SOCKET_DOMAIN, SOCKET_TYPE, 0) ) > 0 ) {  // Create socket, IPv4, TCP
               printf("The Socket was created\n");
               Remote_Send( create_socket, *argv[2], &temperature );              // Send temperature data to remote server  
           } 
           else {
               printf("Fail to create socket\n");
           }

       case '2' :
           //int fd;
           fd = open_port();                                             // Open UART serial port
           if ( fd !=-1 ) {
               printf("Open serial port successfully\n");
               init_serial(fd);                                          // Set up UART parameters
               char ptr[10];
               gcvt( temperature, 5, ptr );                              // Convert double into string, total 5 digits
               write_port( fd, ptr, sizeof(ptr) );                       // Send temperature data via UART                                 
           } 
           else { 
               printf("Fail to open serial port\n");
           }
       default :
           printf("Invalid selection");
     } //End of Switch
  
   return 0;
} // End of Main
