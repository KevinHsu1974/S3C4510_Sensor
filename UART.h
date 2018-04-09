// --------------------------------------------------------------------
//
//   Title     :  UART.h
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  Parameter and function declaration for UART application
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
#ifndef UART_H
#define UART_H

#ifdef __cplusplus
extern "C" {
#endif
/* UART parameters */
#define BAUD_RATE_115200 B115200    // Baud rate = 115200 bps
#define BAUD_RATE_19200  B19200     // Baud rate = 19200  bps
#define UART_PORT "/dev/ttyS1"       // UART port file location 

/* UART port functions */
int open_port(void);
void init_serial(int fd);
int read_data(int fd);
int write_port( int fd, char *data, int size ); 

#ifdef __cplusplus
}
#endif

#endif /* UART_H */

