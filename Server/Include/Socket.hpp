#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <netinet/in.h>

#include <exception>
#include <string>
#include <vector>
#include <ctime>

class Socket
{
private:
    int socketFD, portNo, maxConnections;
    sockaddr_in addr;
    std::vector<int> Connections;

public:
    Socket(int portNo, int maxConnections);
    ~Socket();
    int GetSocketFD() const noexcept;
    int GetPortNo() const noexcept;
    int GetMaxConnections() const noexcept;
    std::vector<int> GetConnections() const noexcept;
    int AcceptConnection();
    void SendMessage(int clientFD, const std::string &message) const;
    bool GetMessage(int clientFD, std::string &received) const;
    int GetActivity(time_t seconds, suseconds_t microSeconds, fd_set &readFds) const noexcept;

private:
    void Disconnect(int clientFD);
    int GetAvailableData(int clientFD) const;
    bool WaitForData(int clientFD, time_t seconds, suseconds_t microSeconds) const;
    bool ReceiveMessage(int clientFD, time_t seconds, suseconds_t microSeconds, std::string &received) const;
};

#endif