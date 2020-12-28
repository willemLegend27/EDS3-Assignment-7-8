#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
#include <iostream>

class MessageHandler
{
private:
    Socket *socket;

public:
    MessageHandler();
    ~MessageHandler();
    void WriteMessage(std::string protocolMessage);

private:
};

#endif