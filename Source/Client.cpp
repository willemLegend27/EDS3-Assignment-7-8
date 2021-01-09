#include "Client.hpp"

Client::Client()
{
}

bool Client::JoinChannel(std::string channelName)
{
    std::cout << "\nSending joinchannel request with name: " << channelName << " to protocol";
    return true;
}