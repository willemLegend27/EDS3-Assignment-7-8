#include "Client.hpp"

Client::Client()
{
    irc = new IRC();
}
Client::~Client()
{
}

void Client::Read(std::string userInput)
{
    std::string message = userInput.substr(userInput.find('{') + 1, userInput.find('}') - 2);
    if (userInput.substr(0, 1) == "s")
    {
        irc->SendMessage(message);
    }
}