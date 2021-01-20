#include "Client.hpp"

Client::Client(int clientFD) : clientFD(clientFD)
{
}

int Client::GetClientFD() const
{
    return clientFD;
}

std::string Client::GetCurrentChannel() const
{
    return currentChannel;
}
void Client::AssignChannel(std::string newChannel)
{
    currentChannel=newChannel;
}