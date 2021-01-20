#ifndef SERVER_HPP
#define SERVER_HPP

#include "MessageHandler.hpp"
#include "Json.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include <vector>

class Server
{
private:
    MessageHandler &messageHandler;
    bool readMessages = true;
    std::vector<Channel> Channels;
    std::vector<Client> Clients;

public:
    Server(MessageHandler &messageHandler);
    ~Server();
    void ReadSocketActivity();

private:
    nlohmann::json MessageToJson();
    Client *FindClient(int clientID);
    Channel *FindChannel(std::string channelName);
    void ReadJoinChannel(int clientID);
    void RemoveMessage();
};

#endif