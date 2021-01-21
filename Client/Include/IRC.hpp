#ifndef IRC_HPP
#define IRC_HPP

#include "../Enums/Events.hpp"
#include "UserInterface.hpp"
#include "Client.hpp"
#include <iostream>

class IRC
{
private:
    UserInterface &userInterface;
    Client *client;
    const std::string serverIP;
    const int serverPort;
    bool run = true;

public:
    IRC(UserInterface &userInterface, const std::string serverIP, const int serverPort);
    virtual ~IRC();
    void Run();

private:
    void HandleEvent(Events event);
    void JoinChannel();
    void LeaveChannel();
    void SendMessage();
};

#endif