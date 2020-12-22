#ifndef IRC_HPP
#define IRC_HPP

#include "Protocol.hpp"
#include <iostream>

class IRC
{
private:
Protocol *protocol;
public:
    IRC();
    ~IRC();
    void SendMessage(std::string message);
    void LeaveChannel();
private:
};

#endif