#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "IRC.hpp"
#include <iostream>

class Client
{
private:
    IRC *irc;
    std::string activeChannel = "";

public:
    Client();
    ~Client();
    void SendMessage(std::string userInput);
    std::string GetActiveChannel();
    std::vector<std::string> GetChannelMessages();

private:
};

#endif