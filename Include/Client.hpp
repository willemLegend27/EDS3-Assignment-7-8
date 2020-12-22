#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "IRC.hpp"
#include <iostream>

class Client
{
private:
    IRC *irc;
    
public:
    Client();
    ~Client();
    void Read(std::string userInput);

private:
};

#endif