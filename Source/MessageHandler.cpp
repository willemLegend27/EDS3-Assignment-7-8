#include "MessageHandler.hpp"

MessageHandler::MessageHandler()
{
    socket = new Socket();
}
MessageHandler::~MessageHandler()
{
}
void MessageHandler::WriteMessage(std::string protocolMessage)
{
    std::cout << "\nMessageHandler has: " + protocolMessage;
}
