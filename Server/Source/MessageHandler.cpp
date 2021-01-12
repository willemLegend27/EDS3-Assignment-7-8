#include "MessageHandler.hpp"
#include <thread>

#include <iostream>

MessageHandler::MessageHandler(Socket &socket) : socket(socket)
{
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::CombineWithClientFD(std::string currentMessage /*int clientFD*/)
{
    nlohmann::json currentJson = nlohmann::json::parse(currentMessage);
    std::cout << currentJson["type"].get<std::string>();
    //nlohmann::json json;
    //json["content"] = {{"clientNr", clientFD}, {"type", currentJson["type"].get<std::string>()}, {"value", currentJson["value"].get<std::string>()}};

    //nlohmann::json json;
    //json["content"] = {{"type", type}, {"value", value}};
    //return json.dump();
}
void MessageHandler::StackIncommingMessage(nlohmann::json messageObject)
{
    IncommingMessages.push_back(messageObject);
    std::cout << IncommingMessages.size();
}

void MessageHandler::Read()
{

    while (true)
    {
        fd_set readFds;
        int nrSockets = socket.GetActivity(this->activity_s, this->activity_ms, readFds);

        if (nrSockets > 0)
        {
            std::cout << "arriving here";
            if (FD_ISSET(socket.GetSocketFD(), &readFds))
            {
                std::cout << "to connect";
                std::cout << socket.AcceptConnection();
                std::cout << "Connected";
            }
            else
            {
                for (auto clientFD : socket.GetConnections())
                {
                    if (FD_ISSET(clientFD, &readFds))
                    {
                        std::string response;
                        bool success = socket.GetMessage(clientFD, response);
                        std::cout << "Response: " << response;
                        if (!success || response == "disc")
                        {
                            socket.Disconnect(clientFD);
                        }
                        else
                        {
                            //HandleMessage(clientFD, response);
                            std::cout << "Response: " << response;
                        }
                    }
                }
            }
        }
    }
}