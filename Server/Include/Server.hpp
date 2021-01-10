#ifndef SERVER_HPP
#define SERVER_HPP

#include "MessageHandler.hpp"
#include <vector>
#include <thread>

class Server
{
private:
    MessageHandler &messageHandler;

public:
    Server(MessageHandler &messageHandler);
    ~Server();

    void ReadSocketActivity();

private:
};

#endif