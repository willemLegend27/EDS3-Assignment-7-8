#include "MessageHandler.hpp"
#include <thread>

#include <iostream>

MessageHandler::MessageHandler(Socket &socket) : socket(socket)
{
}

MessageHandler::~MessageHandler()
{
}

nlohmann::json MessageHandler::CombineWithID(std::string currentMessage, int id)
{

    nlohmann::json currentJson = nlohmann::json::parse(currentMessage);
    std::cout << currentJson["type"].get<std::string>();
    nlohmann::json json;
    json = {{"clientNr", id}, {"type", currentJson["type"].get<std::string>()}, {"value", currentJson["value"].get<std::string>()}};
    return json.dump();
}
void MessageHandler::StackIncommingMessage(nlohmann::json messageObject)
{

    IncommingMessages.push_back(messageObject);
}

std::vector<nlohmann::json> MessageHandler::GetIncommingMessages()
{

    return IncommingMessages;
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
                            std::cout << "received: " << response << '\n';
                            StackIncommingMessage(CombineWithID(response, clientFD));
                        }
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}