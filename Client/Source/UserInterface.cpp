#include "UserInterface.hpp"
#include <vector>

UserInterface::UserInterface()
{
}

void UserInterface::Print(std::string message)
{
    std::cout << message;
}

bool UserInterface::IsNumber(const std::string &input)
{
    for (std::string::const_iterator i = input.begin(); i != input.end(); i++)
    {
        if (!std::isdigit(*i))
        {
            return false;
        }
    }
    return true;
}

void UserInterface::AskConnection(std::string *inputIP, std::string *inputPort)
{
    GetInputServerIP(inputIP);
    GetInputServerPort(inputPort);
}

void UserInterface::GetInputServerIP(std::string *inputIP)
{
    std::cout << "\nInput IP of server to connect with: ";
    std::getline(std::cin, *inputIP);
    std::cout << "\nIP to connect with: " + *inputIP;
}
void UserInterface::GetInputServerPort(std::string *inputPort)
{
    std::cout << "\nInput port of server to connect with: ";
    std::getline(std::cin, *inputPort);
    if (IsNumber(*inputPort))
    {
        std::cout << "\nPort to connect with: " + *inputPort;
    }
}

int UserInterface::GetChoice()
{
    std::string input;
    std::cout << "\nPlease input choice: ";
    std::getline(std::cin, input);
    std::cout << "\nInput: " + input;
    if (IsNumber(input))
    {
        return std::stoi(input);
    }
    return -1;
}

void UserInterface::PrintInterface()
{
    std::cout << "\nIRC Interface";
    std::cout << "\n================================";
    std::cout << "\nClient is currently active on channel: ";
    std::cout << "\n================================";
    std::cout << "\n(1) Join channel";
    std::cout << "\n(2) Leave current channel";
    std::cout << "\n(3) Send message";
    std::cout << "\n(4) Get all messages of channel";
    std::cout << "\n(5) Exit";
    std::cout << "\n================================";
}

std::string UserInterface::GetJoinChannel()
{
    std::cout << "\n Input name of channel you want to join: ";
    std::string channelName = "";
    std::getline(std::cin, channelName);
    std::cout << "\n Input name: " + channelName;
    return channelName;
}

std::string UserInterface::GetMessageToSend()
{
    std::cout << "\n Input message to send: ";
    std::string message = "";
    std::getline(std::cin, message);
    std::cout << "\n Input message: " + message;
    return message;
}

Events UserInterface::GetEvent()
{
    Events result;

    HandlePollEvents();

    if (events.size() > 0)
    {
        result = events[0];
        events.erase(events.begin());
    }

    return result;
}

void UserInterface::HandlePollEvents()
{
    switch (GetChoice())
    {
    case 1:
        PushEvent(Events::JOIN_CHANNEL);
        break;
    case 2:
        PushEvent(Events::LEAVE_CHANNEL);
        break;
    case 3:
        PushEvent(Events::SEND_MESSAGE);
        break;
    case 4:
        PushEvent(Events::GET_CHANNEL_MESSAGES);
        break;
    case 5:
        PushEvent(Events::Quit);
        break;
    default:
        break;
    }
}

void UserInterface::PushEvent(Events event)
{
    events.push_back(event);
}
