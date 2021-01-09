#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "../Enums/Events.hpp"
#include <iostream>
#include <vector>

class UserInterface
{
private:
    std::vector<Events> events;

public:
    UserInterface();
    virtual ~UserInterface() = default;
    void PrintInterface();
    Events GetEvent();
    std::string GetJoinChannel();

private:
    int GetChoice();
    void Print(std::string message);
    bool IsNumber(const std::string &input);
    void HandlePollEvents();
    void PushEvent(Events event);
};

#endif