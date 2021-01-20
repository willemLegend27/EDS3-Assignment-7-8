#include "Server.hpp"

#include <iostream>
#include <string.

Server::Server(MessageHandler &messageHandler) : messageHandler(messageHandler)
{
}
Server::~Server()
{
}

void Server::ReadSocketActivity()
{
    //readThread = std::thread(&MessageHandler::Read, this->messageHandler);
    nlohmann::
    /*
    while (true)
    {
        int incommingMessagesSize = messageHandler.GetIncommingMessages().size();
        if (incommingMessagesSize > 0)
        {

            nlohmann::json message = messageHandler.GetIncommingMessages().front();

            std::string type = message;

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
    */
}