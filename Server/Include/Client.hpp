#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
private:
    int clientFD;
    std::string currentChannel;

public:
    Client(int clientFD);
    ~Client() = default;
    int GetClientFD();
    std::string GetCurrentChannel();
    void AssignChannel(std::string newChannel);

private:
};

#endif