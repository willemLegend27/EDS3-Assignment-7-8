#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
private:
    std::string name;
    int clientFD;

public:
    Client(std::string name, int clientFD);
    ~Client() = default;

private:
};

#endif