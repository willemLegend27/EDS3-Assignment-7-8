#include "Socket.hpp"
#include "Exception.hpp"

#include <unistd.h>
#include <string.h>
#include <vector>
#include <sys/ioctl.h>

Socket::Socket(std::string IPAddress, uint16_t serverPort)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_port = htons(serverPort);
    ServerAddress.sin_addr.s_addr = inet_addr(IPAddress.c_str());
    ConnectToServer();
}
Socket::~Socket()
{
    DisconnectFromServer();
}

int Socket::ConnectToServer()
{
    if (connect(clientSocket, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress)) < 0)
    {
        throw Exception("Connection failed", __FILE__, __LINE__);
    }

    return 0;
}

int Socket::DisconnectFromServer()
{
    if (close(clientSocket) != 0)
    {
        throw Exception("Failed to close connection", __FILE__, __LINE__);
    }

    return 0;
}

int Socket::GetAvailableData() const
{
    int bytesAvailable = 0;
    ioctl(clientSocket, FIONREAD, &bytesAvailable);

    return bytesAvailable;
}

int Socket::ServerRWAvailability()
{
    fd_set rfds, wfds;
    timeval timeoutVal;
    timeoutVal.tv_usec = 0.0;
    timeoutVal.tv_sec = 1;
    FD_ZERO(&rfds);
    FD_ZERO(&wfds);
    FD_SET(clientSocket, &rfds);
    FD_SET(clientSocket, &wfds);
    return select(clientSocket + 1, &rfds, &wfds, NULL, &timeoutVal);
}

bool Socket::ReadMessage(std::string &received)
{
    if (!ServerRWAvailability())
    {
        return false;
    }
    int bytesAvailable = GetAvailableData();

    if (bytesAvailable == 0)
    {
        return false;
    }

    char *buffer = new char[bytesAvailable];
    buffer[bytesAvailable] = '\0';
    ssize_t n = read(clientSocket, buffer, bytesAvailable);
    if (n == -1)
    {
        throw Exception("Error reading from socket\n", __FILE__, __LINE__);
    }
    received = std::string(buffer);
    std::cout << "received: " << received;
    delete[] buffer;

    return true;
}

bool Socket::WriteMessage(std::string protocolMessage)
{
    if (!ServerRWAvailability())
    {
        return false;
    }
    size_t nmbrOfBytes = send(clientSocket, protocolMessage.c_str(), strlen(protocolMessage.c_str()), 0);

    if (nmbrOfBytes != strlen(protocolMessage.c_str()))
    {
        throw Exception("Message was not send correctly", __FILE__, __LINE__);
        return false;
    }
    return true;
}