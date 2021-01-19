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
        int incommingMessagesSize = messageHandler.GetIncommingMessages().size();
        if (incommingMessagesSize > 0)
        {
            nlohmann::json message = messageHandler.GetIncommingMessages().at(0);
            std::cout << "\n"
                      << incommingMessagesSize;
            std::string type = message["type"].get<std::string>();
            std::cout << type;
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