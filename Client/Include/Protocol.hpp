#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include "Json.hpp"
#include "MessageHandler.hpp"
#include <iostream>

class Protocol
{
private:
    MessageHandler *messageHandler;

public:
    Protocol();
    ~Protocol();
    bool SendMessage(std::string message);
    bool JoinChannel(std::string channelName);
    bool LeaveChannel(std::string channelName);
    std::vector<nlohmann::json> GetChannelMessages();

private:
    std::string FormatToJson(std::string type, std::string value);
};

#endif