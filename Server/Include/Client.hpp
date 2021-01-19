#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
private:
    int clientFD;

public:
    Client(int clientFD);
    ~Client() = default;

private:
};

#endif