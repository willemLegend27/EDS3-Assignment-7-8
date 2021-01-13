#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <arpa/inet.h>
#include <ctime>

class Socket
{
private:
    int clientSocket = 0;
    uint16_t serverPort;
    struct sockaddr_in ServerAddress;

public:
    Socket(std::string IPAddress, uint16_t serverPort);
    ~Socket();
    bool ReadMessage(std::string &received);
    bool WriteMessage(std::string protocolMessage);

private:
    int ConnectToServer();
    int DisconnectFromServer();
    int GetAvailableData() const;
    int ServerRWAvailability();
};

#endif