#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
#include <iostream>
#include <vector>
#include <thread>

class MessageHandler
{
private:
    Socket *socket;
    std::vector<std::string> ChannelMessages;
    std::thread readThread;
    std::thread writeThread;
    bool read = true;

public:
    MessageHandler();
    ~MessageHandler();
    void SendMessage(std::string protocolMessage);
    std::vector<std::string> GetChannelMessages();

private:
    void ReadMessage();
    void WriteMessage(std::string protocolMessage);
};

#endif