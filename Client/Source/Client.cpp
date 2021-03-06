#include "Client.hpp"

Client::Client(const std::string serverIP, const int serverPort) : serverIP(serverIP), serverPort(serverPort)
{
    protocol = new Protocol(serverIP, serverPort);
}

Client::~Client()
{
    delete protocol;
    protocol = nullptr;
}

bool Client::JoinChannel(std::string channelName)
{
    if (protocol->JoinChannel(channelName))
    {
        return true;
    }
    return false;
}

bool Client::LeaveChannel()
{
    if (protocol->LeaveChannel(activeChannel))
    {
        return true;
    }
    return false;
}

bool Client::SendMessage(std::string message)
{
    if (protocol->SendMessage(message))
    {
        return true;
    }
    return false;
}

const std::string Client::GetActiveChannel()
{
    return activeChannel;
}