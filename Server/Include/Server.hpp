#ifndef SERVER_HPP
#define SERVER_HPP

#include "MessageHandler.hpp"
#include <vector>
#include <thread>

class Server
{
private:
    MessageHandler &messageHandler;
    bool readMessages = true;
    std::thread readThread;

public:
    Server(MessageHandler &messageHandler);
    ~Server();
    void ReadSocketActivity();
    

private:
};

#endif