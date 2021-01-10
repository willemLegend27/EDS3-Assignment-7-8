#include "IRC.hpp"

IRC::IRC(UserInterface &userInterface, Client &client) : userInterface(userInterface), client(client)
{
}

void IRC::Run()
{
    userInterface.PrintInterface();
    Events event = userInterface.GetEvent();
    HandleEvent(event);
}

void IRC::HandleEvent(Events event)
{
    std::string message = "";
    switch (event)
    {
    case NO_EVENT_OCCURED:
        break;
    case JOIN_CHANNEL:
        message = userInterface.GetJoinChannel();
        client.JoinChannel(message);
        break;
    case LEAVE_CHANNEL:
        break;
    case SEND_MESSAGE:
        break;
    case GET_CHANNEL_MESSAGES:
        break;
    default:
        break;
    }
}