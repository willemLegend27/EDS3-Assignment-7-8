#include "MessageHandler.hpp"

MessageHandler::MessageHandler(const std::string serverIP, const int serverPort) : serverIP(serverIP), serverPort(serverPort)
{
    socket = new Socket(serverIP, serverPort);
    readThread = std::thread(&MessageHandler::ReadMessage, this);
}

MessageHandler::~MessageHandler(){}
{
}

bool MessageHandler::SendMessage(std::string protocolMessage)
{
    if (socket->WriteMessage(protocolMessage))
    {
        return true;
    }
    return false;
}

void MessageHandler::ReadMessage()
{
    while (read)
    {

        std::string incoming;
        if (socket->ReadMessage(incoming))
        {
            {
                std::lock_guard<std::mutex> guard(mutex);
                ChannelMessages.push_back(incoming);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

std::vector<std::string> MessageHandler::GetChannelMessages()
{
    {
        std::lock_guard<std::mutex> guard(mutex);
        return ChannelMessages;
    }
}
