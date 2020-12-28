#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>

class Socket
{
private:
public:
    Socket();
    ~Socket();
    std::string Read();
    void WriteMessage(std::string /*protocolMessage*/);

private:
};

#endif