#ifndef SERVER_HPP
#define SERVER_HPP

#include "MessageHandler.hpp"
#include "Json.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include <vector>
//#include <thread>

class Server
{
private:
    MessageHandler &messageHandler;
    bool readMessages = true;
    //std::thread readThread;
    std::vector<Channel> Channels;
    std::vector<Client> Clients;

public:
    Server(MessageHandler &messageHandler);
    ~Server();
    void ReadSocketActivity();

private:
};

#endif