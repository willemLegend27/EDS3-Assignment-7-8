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

    switch (event)
    {
    case NO_EVENT_OCCURED:
        break;
    case JOIN_CHANNEL:
        JoinChannel();
        break;
    case LEAVE_CHANNEL:
        LeaveChannel();
        break;
    case SEND_MESSAGE:
        SendMessage();
        break;
    case GET_CHANNEL_MESSAGES:
        break;
    default:
        break;
    }
}

void IRC::JoinChannel()
{
    std::string message = userInterface.GetJoinChannel();
    if (client.JoinChannel(message))
    {
        userInterface.Print(std::string("\nRequested server to join channel: " + message));
    }
}
void IRC::LeaveChannel()
{
    if (client.GetActiveChannel() == "")
    {
        userInterface.Print("\nNo channel active, join one first");
        return;
    }
    if (client.LeaveChannel())
    {
        userInterface.Print("\nRequested server to leave current channel");
    }
}
void IRC::SendMessage()
{
    if (client.GetActiveChannel() == "")
    {
        userInterface.Print("\nNo channel active, join one first");
        return;
    }
    std::string message = userInterface.GetMessageToSend();
    if (client.SendMessage(message))
    {
        userInterface.Print(std::string("\nSend message: " + message + " to server"));
    }
}