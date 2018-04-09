// --------------------------------------------------------------------
//
//   Title     :  UART.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  UART application
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
#include <stdio.h> /* Standard input/output definitions */
#include <string.h> /* String function definitions */
#include <unistd.h> /* UNIX standard function definitions */
#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "UART.h"

int  open_port(void) {         
     int fd;                                               //fd: File descriptor for the port 	 
     fd = open(UART_PORT, O_RDWR | O_NOCTTY | O_NDELAY);   // Open port        
     
     /* Check if port open has been done successfully */
     if ( fd == -1 ) {                                        
	printf("open_port: Unable to open %s\n", UART_PORT);
     }
     else {
	printf("\n Open serial OK~\n");
	fcntl(fd, F_SETFL, 0);
     }
     return (fd);
}

void init_serial(int fd) {
     struct termios options; 
     
     tcgetattr( fd, &options );                   // Get the current options for the port  
     cfsetispeed( &options, BAUD_RATE_115200 );   // Set the input baud rates to 115200     
     cfsetospeed( &options, BAUD_RATE_115200 );   // Set the output baud rates to 115200
           
     options.c_cflag |= ( CLOCAL | CREAD );       // Enable the receiver and set local mode
     options.c_cflag &= ~CSIZE;
     options.c_cflag |= CS8;                      // 8-bit data length
   
     tcsetattr( fd, TCSANOW, &options );          // Set the new options for the port
   
}

int read_data(int fd) {
     char buffer[255];	                         // Input buffer
     char *bufptr; 		                 // Current char in buffer
     int nbytes; 		                 // Number of bytes read
	     
     /* read characters into our string buffer until we get a CR or NL */
     bufptr = buffer;
     while ( (nbytes = read(fd, bufptr, buffer + sizeof(buffer)-bufptr-1)) > 0 ) {
	bufptr += nbytes;
	if (bufptr[-1] == '\n' || bufptr[-1] == '\r')
	    break;
     }
	
     /* null terminate the string and see if we got an OK response */
     *bufptr = '\0';
	
     printf("\n %s \n",buffer);
     
     return (0);
}

int write_port( int fd, char *data, int size ) {	
     int n;
     n = write( fd, data, size );       // Write data to port
     if ( n < 0 )
	fputs( "Fail to write data!\n", stderr );	
     
     return(0);
}


