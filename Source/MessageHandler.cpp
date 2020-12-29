#include "MessageHandler.hpp"

MessageHandler::MessageHandler()
{
    socket = new Socket((0, 0, 0, 0), 3333);
}
MessageHandler::~MessageHandler()
{
}
void MessageHandler::WriteMessage(std::string protocolMessage)
{
    std::cout << "\nMessageHandler has: " + protocolMessage;
}
