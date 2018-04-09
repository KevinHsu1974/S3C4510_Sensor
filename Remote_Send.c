// --------------------------------------------------------------------
//
//   Title     :  Remote_Send.c
//             :
//   Developers:  Kevin Hsu
//             :
//   Purpose   :  Client application for remote  connection
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

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "Remote_Send.h"

void Remote_Send(int create_socket, char s_addr, double *data) {
   struct sockaddr_in address;                     // Socket address 
   
   address.sin_family = SOCKET_DOMAIN;             // Assign domain
   address.sin_port = htons(TCP_PORT);             // Assign TCP port
   inet_pton(SOCKET_DOMAIN, s_addr, &address.sin_addr ); // Assign remote server address
   
   // Build connection to remote server
   if ( connect( create_socket, (struct sockaddr *)&address, sizeof(address) ) < 0 ) {
     perror("connect error");                       
     return 1;
   }

   send( create_socket, data, sizeof(*data), 0 );  // Send data to remote server

   close( create_socket );
}