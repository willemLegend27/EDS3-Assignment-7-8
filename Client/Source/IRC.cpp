#include "IRC.hpp"

IRC::IRC(UserInterface &userInterface, const std::string serverIP, const int serverPort) : userInterface(userInterface), serverIP(serverIP), serverPort(serverPort)
{
    client = new Client(serverIP, serverPort);
    while (run)
    {
        Run();
    }
}

IRC::~IRC()
{
    delete client;
    client = nullptr;
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
    case Quit:
        std::cout << "Quitting app....";
        run = false;
        break;
    default:
        break;
    }
}

void IRC::JoinChannel()
{
    std::string message = userInterface.GetJoinChannel();
    if (client->JoinChannel(message))
    {
        userInterface.Print(std::string("\nRequested server to join channel: " + message));
    }
}
void IRC::LeaveChannel()
{
    if (client->GetActiveChannel() == "")
    {
        userInterface.Print("\nNo channel active, join one first");
        return;
    }
    if (client->LeaveChannel())
    {
        userInterface.Print("\nRequested server to leave current channel");
    }
}
void IRC::SendMessage()
{
    if (client->GetActiveChannel() == "")
    {
        userInterface.Print("\nNo channel active, join one first");
        return;
    }
    std::string message = userInterface.GetMessageToSend();
    if (client->SendMessage(message))
    {
        userInterface.Print(std::string("\nSend message: " + message + " to server"));
    }
}