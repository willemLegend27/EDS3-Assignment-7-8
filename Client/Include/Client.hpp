#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Protocol.hpp"
#include <iostream>

class Client
{
private:
    Protocol* protocol;
    std::string activeChannel = "";

public:
    Client();
    virtual ~Client() = default;
    bool JoinChannel(std::string channelName);

private:
};

#endif