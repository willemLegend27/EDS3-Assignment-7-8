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
    Client &client;

public:
    IRC(UserInterface &userInterface, Client &client);
    virtual ~IRC() = default;
    void Run();

private:
    void HandleEvent(Events event);
};

#endif