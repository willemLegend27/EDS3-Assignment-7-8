#include "MessageHandler.hpp"

#include <iostream>

MessageHandler::MessageHandler(Socket &socket) : socket(socket)
{
    readThread = std::thread(&MessageHandler::Read, this);
}

MessageHandler::~MessageHandler()
{
}

std::string MessageHandler::CombineWithID(std::string currentMessage, int id)
{
    std::string appendID = ",\"id\": \"" + std::to_string(id) + "\" }";
    currentMessage.replace(currentMessage.end() - 1, currentMessage.end(), appendID);
    return currentMessage;
}

void MessageHandler::StackIncommingMessage(std::string messageObject)
{
    {
        std::lock_guard<std::mutex> guard(mutex);
        IncommingMessages.push_back(messageObject);
    }
}

std::vector<std::string> MessageHandler::GetIncommingMessages()
{
    {
        std::lock_guard<std::mutex> guard(mutex);
        return IncommingMessages;
    }
}

bool MessageHandler::EraseFromInCommingMessages(size_t pos)
{
    if (IncommingMessages.size() > pos)
    {
        {
            std::lock_guard<std::mutex> guard(mutex);
            IncommingMessages.erase(IncommingMessages.begin() + pos);
            return true;
        }
    }
    return false;
}

void MessageHandler::SendMessage(int clientFD, std::string protocolMessage)
{
    socket.SendMessage(clientFD, protocolMessage);
}

void MessageHandler::Read()
{
    while (true)
    {
        fd_set readFds;
        int nrSockets = this->socket.GetActivity(this->activity_s, this->activity_ms, readFds);

        if (nrSockets > 0)
        {
            if (FD_ISSET(this->socket.GetSocketFD(), &readFds))
            {
                this->socket.AcceptConnection();
                std::cout << "\nClient connected";
            }
            else
            {
                for (auto clientFD : this->socket.GetConnections())
                {
                    if (FD_ISSET(clientFD, &readFds))
                    {
                        std::string response;
                        bool success = this->socket.GetMessage(clientFD, response);

                        if (success)
                        {
                            std::cout << "\nReceived: " << response;
                            StackIncommingMessage(CombineWithID(response, clientFD));
                        }
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}