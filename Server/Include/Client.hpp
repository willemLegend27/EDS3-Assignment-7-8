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
    virtual ~Client() = default;
    int GetClientFD() const;
    std::string GetCurrentChannel() const;
    void AssignChannel(std::string newChannel);

private:
};

#endif