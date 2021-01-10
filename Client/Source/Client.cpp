#include "Client.hpp"

Client::Client()
{
    protocol = new Protocol();
}

bool Client::JoinChannel(std::string channelName)
{
    std::cout << "\nSending joinchannel request with name: " << channelName << " to protocol";
    protocol->JoinChannel(channelName);
    return true;
}