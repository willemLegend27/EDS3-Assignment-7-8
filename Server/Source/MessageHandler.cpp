#include "MessageHandler.hpp"

#include <iostream>

MessageHandler::MessageHandler(Socket &socket) : socket(socket)
{
    //readThread = std::thread(&MessageHandler::Read, this);
}

MessageHandler::~MessageHandler()
{
}

nlohmann::json MessageHandler::CombineWithID(std::string currentMessage, int id)
{

    nlohmann::json currentJson = nlohmann::json::parse(currentMessage);
    nlohmann::json newJson;
    newJson = {{"clientNr", id}, {"type", currentJson["type"].get<std::string>()}, {"value", currentJson["value"].get<std::string>()}};
    return newJson.dump();
}

void MessageHandler::StackIncommingMessage(nlohmann::json messageObject)
{
    {
        std::lock_guard<std::mutex> guard(mutex);
        IncommingMessages.push_back(messageObject);
    }

    std::cout << IncommingMessages.at(0);
    nlohmann::json obj = IncommingMessages.at(0);
    nlohmann::json newOjb = obj["type"];
    if (!newOjb.is_null())
    {
        std::string value = newOjb["type"].get<std::string>();
    }
}

std::vector<nlohmann::json> MessageHandler::GetIncommingMessages()
{
    {
        std::lock_guard<std::mutex> guard(mutex);
        return IncommingMessages;
    }
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
            }
            else
            {
                for (auto clientFD : this->socket.GetConnections())
                {
                    if (FD_ISSET(clientFD, &readFds))
                    {
                        std::string response;
                        bool success = this->socket.GetMessage(clientFD, response);

                        if (!success || response == "disc")
                        {
                            this->socket.Disconnect(clientFD);
                        }
                        else
                        {
                            StackIncommingMessage(CombineWithID(response, clientFD));
                        }
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}