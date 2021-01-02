#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "Client.hpp"
#include <iostream>

class UserInterface
{
private:
    Client *client;

public:
    UserInterface();
    ~UserInterface();
    void GetChoice();
    void PrintInterface();

private:
    void Print(std::string message);
    void ActOnChoice(int choice);
    bool IsNumber(const std::string &input);
    void SendMessage();
    void JoinChannel();
    void LeaveChannel();
    void GetChannelMessages();
};

#endif