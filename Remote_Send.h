// --------------------------------------------------------------------
//
//   Title     :  Remote_Send.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  Client application for remote connection
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

#ifndef REMOTE_SEND_H
#define REMOTE_SEND_H

#ifdef __cplusplus
extern "C" {
#endif
/* Connection parameters*/
#define SOCKET_DOMAIN  AF_INET
#define SOCKET_TYPE    SOCK_STREAM 
#define TCP_PORT       15000

/* Socket functions*/    
void Remote_Send(int create_socket, char s_addr, double *data);

#ifdef __cplusplus
}
#endif

#endif /* REMOTE_SEND_H */

