#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
private:
    std::string activeChannel = "";

public:
    Client();
    virtual ~Client() = default;
    bool JoinChannel(std::string channelName);

private:
};

#endif