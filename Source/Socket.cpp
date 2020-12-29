#include "Socket.hpp"
#include "Exception.hpp"

#include <unistd.h>
#include <string.h>
#include <vector>

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
std::string Socket::Read()
{
    std::vector<char> buffer;
    buffer.resize(BufferSize);
    int bytes = recv(clientSocket, buffer.data(), buffer.size(), 0);
    if (bytes != -1)
    {
        buffer.resize(bytes);
        return std::string(buffer.begin(), buffer.end());
    }
    return "";
}
void Socket::WriteMessage(std::string protocolMessage)
{
    size_t nmbrOfBytes = send(clientSocket, protocolMessage.c_str(), strlen(protocolMessage.c_str()), 0);

    if (nmbrOfBytes != strlen(protocolMessage.c_str()))
    {
        throw Exception("Message was not send correctly", __FILE__, __LINE__);
    }
}