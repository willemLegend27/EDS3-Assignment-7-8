#include "Socket.hpp"
#include "Exception.hpp"

#include <unistd.h>
#include <sys/ioctl.h>

#include <cstring>
#include <sstream>
#include <algorithm>

Socket::Socket(int portNo, int maxConnections) : portNo(portNo), maxConnections(maxConnections)
{
    socketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (socketFD == -1)
    {
        throw Exception("Error opening socket", __FILE__, __LINE__);
    }

    memset(&addr, 0, sizeof addr);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;

    addr.sin_port = htons(portNo);

    if (bind(socketFD, (sockaddr *)&addr, sizeof addr) == -1)
    {
        throw Exception("Error on binding", __FILE__, __LINE__);
    }

    listen(socketFD, maxConnections);
}

Socket::~Socket()
{
    for (auto clientFD : connections)
    {
        Disconnect(clientFD);
    }
    close(socketFD);
}

int Socket::GetSocketFD() const noexcept
{
    return socketFD;
}

int Socket::GetPortNo() const noexcept
{
    return portNo;
}

int Socket::GetMaxConnections() const noexcept
{
    return maxConnections;
}

std::vector<int> Socket::GetConnections() const noexcept
{
    return connections;
}

int Socket::AcceptConnection()
{
    sockaddr_in clientAddress;
    socklen_t clilen = sizeof clientAddress;

    int clientFD = accept(socketFD, reinterpret_cast<sockaddr *>(&clientAddress), &clilen);

    if (clientFD == -1)
    {
        throw Exception("Error on accept", __FILE__, __LINE__);
    }

    connections.push_back(clientFD);

    return clientFD;
}

void Socket::Disconnect(int clientFD)
{
    connections.erase(std::remove(connections.begin(), connections.end(), clientFD));

    close(clientFD);
}

int Socket::GetAvailableData(int clientFD) const
{
    int bytesAvailable = 0;
    ioctl(clientFD, FIONREAD, &bytesAvailable);

    return bytesAvailable;
}

bool Socket::WaitForData(int clientFD, time_t seconds, suseconds_t microSeconds) const
{
    fd_set readFds;
    FD_ZERO(&readFds);
    FD_SET(clientFD, &readFds);

    timeval time;
    time.tv_sec = seconds;
    time.tv_usec = microSeconds;

    bool result = select(FD_SETSIZE, &readFds, nullptr, nullptr, &time);

    return result;
}

void Socket::SendMessage(int clientFD, const std::string &message) const
{
    if (write(clientFD, message.c_str(), message.length() + 1) == -1)
    {
        throw Exception("Error writing to socket", __FILE__, __LINE__);
    }
}

bool Socket::GetMessage(int clientFD, std::string &received) const
{
    int bytesAvailable = GetAvailableData(clientFD);

    if (bytesAvailable == 0)
    {
        return false;
    }

    char *buffer = new char[bytesAvailable];
    buffer[bytesAvailable] = '\0';

    ssize_t n = read(clientFD, buffer, bytesAvailable);

    if (n == -1)
    {
        throw Exception("Error reading from socket\n", __FILE__, __LINE__);
    }

    received = std::string(buffer);
    delete[] buffer;

    return true;
}

bool Socket::ReceiveMessage(int clientFD, time_t seconds, suseconds_t microSeconds, std::string &received) const
{
    bool dataAvailable = WaitForData(clientFD, seconds, microSeconds);

    if (!dataAvailable)
    {
        return false;
    }

    GetMessage(clientFD, received);

    return true;
}

int Socket::GetActivity(time_t seconds, suseconds_t microSeconds, fd_set &readFds) const noexcept
{
    FD_ZERO(&readFds);
    FD_SET(socketFD, &readFds);

    for (auto clientFD : connections)
    {
        FD_SET(clientFD, &readFds);
    }

    timeval timout;
    timout.tv_sec = seconds;
    timout.tv_usec = microSeconds;

    int nrSockets = select(FD_SETSIZE, &readFds, nullptr, nullptr, &timout);

    return nrSockets;
}
