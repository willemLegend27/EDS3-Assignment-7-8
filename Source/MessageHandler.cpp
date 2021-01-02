#include "MessageHandler.hpp"

MessageHandler::MessageHandler()
{
    const std::string serverIP = "0.0.0.0";
    const int serverPort = 5001;
    socket = new Socket(serverIP, serverPort);
    ChannelMessages = new std::vector<std::string>;
    readThread = std::thread(&MessageHandler::ReadMessage, this);
}
MessageHandler::~MessageHandler()
{
}
void MessageHandler::WriteMessage(std::string protocolMessage)
{
    socket->WriteMessage(protocolMessage);
}

void MessageHandler::ReadMessage()
{
    while (read)
    {
        std::string incoming = socket->Read();
        if (incoming != "")
        {

            ChannelMessages->push_back(incoming);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

std::vector<std::string> *MessageHandler::GetChannelMessages()
{
    return ChannelMessages;
}
