#include "Server.hpp"

#include <iostream>

Server::Server(MessageHandler &messageHandler) : messageHandler(messageHandler)
{
}
Server::~Server()
{
}

void Server::ReadSocketActivity()
{
    readThread = std::thread(&MessageHandler::Read, this->messageHandler);
    while (true)
    {
        nlohmann::json message = messageHandler.GetIncommingMessages().at(0);
        if (message)
        {
            std::string type = message["type"].get<std::string>();
            if (type == "join_channel")
            {
            }
            else if (type == "leave_channel")
            {
            }
            else if (type == "message")
            {
            }
        }
    }
}