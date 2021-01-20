#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Protocol.hpp"
#include <iostream>

class Client
{
private:
    Protocol *protocol;
    std::string activeChannel = "";
    const std::string serverIP;
    const int serverPort;

public:
    Client(const std::string serverIP, const int serverPort);
    virtual ~Client() = default;
    bool JoinChannel(std::string channelName);
    bool LeaveChannel();
    bool SendMessage(std::string message);
    std::string GetActiveChannel();

private:
};

#endif