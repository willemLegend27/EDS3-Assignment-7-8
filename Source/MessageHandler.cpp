#include "MessageHandler.hpp"
#include <mutex>

MessageHandler::MessageHandler()
{
    const std::string serverIP = "0.0.0.0";
    const int serverPort = 5001;
    socket = new Socket(serverIP, serverPort);
    readThread = std::thread(&MessageHandler::ReadMessage, this);
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::SendMessage(std::string protocolMessage)
{
    socket->WriteMessage(protocolMessage);
}

void MessageHandler::ReadMessage()
{
    while (read)
    {
        {
            std::lock_guard<std::mutex> guard(std::mutex mutex);
            std::string incoming;
            if (socket->ReadMessage(&incoming))
            {
                ChannelMessages.push_back(incoming);
            }
        }
        for (std::vector<std::string>::iterator t = ChannelMessages.begin(); t != ChannelMessages.end(); ++t)
        {
            std::cout << "\n test getting content of ChannelMessages: " << *t;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

std::vector<std::string> MessageHandler::GetChannelMessages()
{
    return ChannelMessages;
}
