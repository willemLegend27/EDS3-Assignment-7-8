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
    void AskConnection(std::string *inputIP, std::string *inputPort);
    void PrintInterface();
    void Print(std::string message);
    Events GetEvent();
    std::string GetJoinChannel();
    std::string GetMessageToSend();

private:
    int GetChoice();
    void HandlePollEvents();
    void PushEvent(Events event);
    void GetInputServerIP(std::string *serverIP);
    void GetInputServerPort(std::string *serverPort);
    bool IsNumber(const std::string &input);
};

#endif