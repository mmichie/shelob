#include <cerrno>

#include "global.h"
#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <cstdio>
#include <string>
#include <arpa/inet.h>
#include <iostream>

class Socket {

private:
    int socket_fd, sin_size;    
    FILE *socket_fp;    
    struct sockaddr_in server;     
    const static int NUM_CLIENTS_TO_QUEUE = 10; 
    void serverBind(int server_port);
  
public:  
    int accept_fd, pid;

    struct sockaddr_in client;

    void acceptClient();
    bool readLine(string *buffer);
    void writeLine(string line);
    void closeSocket();

    // Constructor
    Socket(int server_port) {
		//Bind the port
		serverBind(server_port);	
    }
};