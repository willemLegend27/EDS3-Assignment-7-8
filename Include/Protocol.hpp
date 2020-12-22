#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <iostream>

class Protocol
{
private:
public:
    Protocol();
    ~Protocol();
    void SendMessage(std::string message);
    void LeaveChannel();

private:
};

#endif