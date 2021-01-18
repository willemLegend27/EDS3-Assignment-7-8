#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class MessageHandler
{
private:
    Socket *socket;
    std::vector<std::string> ChannelMessages;
    std::thread readThread;
    std::mutex mutex;
    bool read = true;

public:
    MessageHandler();
    ~MessageHandler();
    bool SendMessage(std::string protocolMessage);
    std::vector<std::string> GetChannelMessages();

private:
    void ReadMessage();
};

#endif