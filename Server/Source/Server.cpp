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
    //readThread = std::thread(&MessageHandler::Read, this->messageHandler);
    //readThread.detach();
    messageHandler.Read();
}