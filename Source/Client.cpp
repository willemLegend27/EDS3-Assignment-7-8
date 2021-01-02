#include "Client.hpp"

Client::Client()
{
    irc = new IRC();
}
Client::~Client()
{
}

void Client::SendMessage(std::string userInput)
{

    std::string message = userInput.substr(userInput.find('{') + 1, userInput.find('}') - 2);
    if (userInput.substr(0, 1) == "s")
    {
        irc->SendMessage(message);
    }
    else if (userInput.substr(0, 1) == "j")
    {
        irc->JoinChannel(message);
    }
}

std::string Client::GetActiveChannel()
{
    return activeChannel;
}

std::vector<std::string> Client::GetChannelMessages()
{
    std::vector<std::string> messages;
    return messages;
}