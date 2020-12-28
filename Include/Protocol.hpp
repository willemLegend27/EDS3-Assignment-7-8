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
    void LeaveChannel();

private:
    std::string FormatToJson(std::string type, std::string value);
};

#endif