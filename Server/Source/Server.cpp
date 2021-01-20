#include "Server.hpp"

#include <iostream>
#include <string>
#include "JsonReader.hpp"

Server::Server(MessageHandler &messageHandler) : messageHandler(messageHandler)
{
}
Server::~Server()
{
}

void Server::ReadSocketActivity()
{
    while (true)
    {

        int incommingMessagesSize = messageHandler.GetIncommingMessages().size();
        if (incommingMessagesSize > 0)
        {
            std::string id;
            bool containsID = JsonReader::GetValue<std::string>(MessageToJson(), "id", id);
            if (containsID)
            {
                if (!FindClient(stoi(id)))
                {
                    Client client(stoi(id));
                    Clients.push_back(client);
                    std::cout << "Added new client";
                }
                else
                {
                    std::string type;
                    bool containsType = JsonReader::GetValue<std::string>(MessageToJson(), "type", type);
                    if (containsType)
                    {

                        if (type == "join_channel")
                        {
                            ReadJoinChannel(stoi(id));
                        }
                        else if (type == "leave_channel")
                        {
                        }
                        else if (type == "message")
                        {
                            std::string value;
                            bool containsValue = JsonReader::GetValue<std::string>(MessageToJson(), "value", value);
                            if (containsValue)
                            {
                                std::cout << "\n"
                                          << value;
                            }
                        }
                    }
                }
            }
        }
        RemoveMessage();
    }
}

void Server::RemoveMessage()
{
    if (messageHandler.EraseFromInCommingMessages(0))
    {
        std::cout << "Messages is taken care of";
    }
    else
    {
        std::cout << "Message still exists in list";
    }
}

void Server::ReadJoinChannel(int cliendID)
{
    std::string value;
    bool containsValue = JsonReader::GetValue<std::string>(MessageToJson(), "value", value);
    if (containsValue)
    {
        std::cout << "\nReceived request from client: " << cliendID << " to join channel: " << value;
        if (!FindChannel(value))
        {
            std::cout << "\nChannel does not exist";
        }
        else
        {
            std::cout << "\nAssigning client to channel:" << value;
            FindClient(cliendID)->AssignChannel(value);
            messageHandler.SendMessage(cliendID, "Joined succesfully");
        }
    }
}

Client *Server::FindClient(int clientID)
{
    for (auto &i : Clients)
    {
        if (i.GetClientFD() == clientID)
        {
            return &i;
        }
    }
    return NULL;
}

Channel *Server::FindChannel(std::string channelName)
{

    for (auto &i : Channels)
    {
        if (i.GetChannelName() == channelName)
        {
            return &i;
        }
    }
    return NULL;
}

nlohmann::json Server::MessageToJson()
{
    std::string message = messageHandler.GetIncommingMessages().front();
    nlohmann::json JsonMessage;
    try
    {
        JsonMessage = nlohmann::json::parse(message);
    }
    catch (const std::exception &e)
    {
        std::cerr << "could not parse the message, aborting...\n";
    }
    return JsonMessage;
}