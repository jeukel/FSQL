#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include "user.h"
#include "decriptor.h"

class TCPServer
{
public:
    TCPServer(int *portno);
    TCPServer();
    void error(const char *msg);
    void receive();

private:
    int listenPort;
};

#endif // TCPSERVER_H
