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
    void SendMessage(std::string message);
    void JoinChannel(std::string channelName);
    void LeaveChannel();
    std::vector<nlohmann::json> GetChannelMessages();

private:
    std::string FormatToJson(std::string type, std::string value);
};

#endif