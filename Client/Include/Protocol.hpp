#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include "Json.hpp"
#include "MessageHandler.hpp"
#include <iostream>

class Protocol
{
private:
    MessageHandler *messageHandler;
    const std::string serverIP;
    const int serverPort;

public:
    Protocol(const std::string serverIP, const int serverPort);
    ~Protocol();
    bool SendMessage(std::string message);
    bool JoinChannel(std::string channelName);
    bool LeaveChannel(std::string channelName);
    std::vector<std::string> GetChannelMessages();

private:
    std::string FormatToJson(std::string type, std::string value);
};

#endif