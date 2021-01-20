#include "Client.hpp"

Client::Client(int clientFD) : clientFD(clientFD)
{
}

int Client::GetClientFD()
{
    return clientFD;
}

std::string Client::GetCurrentChannel()
{
    return currentChannel;
}
void Client::AssignChannel(std::string newChannel)
{
    currentChannel=newChannel;
}