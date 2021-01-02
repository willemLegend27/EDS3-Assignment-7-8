#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <arpa/inet.h>

class Socket
{
private:
    int clientSocket = 0;
    uint16_t serverPort;
    struct sockaddr_in ServerAddress;
    const int BufferSize = 5000;

public:
    Socket(std::string IPAddress, uint16_t serverPort);
    ~Socket();
    std::string Read();
    void WriteMessage(std::string protocolMessage);

private:
    int ConnectToServer();
    int DisconnectFromServer();
};

#endif