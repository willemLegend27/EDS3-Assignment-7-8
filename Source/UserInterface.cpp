#include "UserInterface.hpp"
#include <vector>

UserInterface::UserInterface()
{
    client = new Client();
}

UserInterface::~UserInterface()
{
}

void UserInterface::Print(std::string message)
{
    std::cout << message;
}

void UserInterface::GetChoice()
{
    std::string input;
    std::cout << "\nPlease input choice: ";
    getline(std::cin, input);
    std::cout << "\nInput: " + input;
    if (IsNumber(input))
    {
        ActOnChoice(std::stoi(input));
    }
}

void UserInterface::PrintInterface()
{
    std::cout << "IRC Interface";
    std::cout << "\n================================";
    std::cout << "\nClient is currently active on channel: " + client->GetActiveChannel();
    std::cout << "\n================================";
    std::cout << "\n(1) Join channel";
    std::cout << "\n(2) Leave current channel";
    std::cout << "\n(3) Send message";
    std::cout << "\n(4) Get all messages of channel";
    std::cout << "\n(5) Exit";
    std::cout << "\n================================";
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

void UserInterface::ActOnChoice(int choice)
{
    switch (choice)
    {
    case 1:
        JoinChannel();
        break;
    case 2:
        LeaveChannel();
        break;
    case 3:
        SendMessage();
        break;
    case 4:
        GetChannelMessages();
        break;
    default:
        std::cout << "\nInvalid input";
        break;
    }
}

void UserInterface::SendMessage()
{
    if (client->GetActiveChannel() != "")
    {
        std::string message;
        std::cout << "\nInput message to send: ";
        getline(std::cin, message);
        std::cout << "\nSending message: " + message;
        client->SendMessage("s{" + message + "}");
        return;
    }
    std::cout << "\n No channel active, join a channel first";
}

void UserInterface::JoinChannel()
{
    std::string channelName;
    std::cout << "\nName of channel to join: ";
    getline(std::cin, channelName);
    std::cout << "\nSending request to join channel: " + channelName;
    client->SendMessage("j{" + channelName + "}");
}

void UserInterface::LeaveChannel()
{
    if (client->GetActiveChannel() != "")
    {
        std::cout << "\nSending request to leave channel: " + client->GetActiveChannel();
        client->SendMessage("l{" + client->GetActiveChannel() + "}");
        return;
    }
    std::cout << "\n No channel active, join a channel first";
}

void UserInterface::GetChannelMessages()
{
    if (client->GetActiveChannel() != "")
    {

        std::cout << "\nMessages of in current channel: " + client->GetActiveChannel();
        std::vector<std::string> messages = client->GetChannelMessages();
        return;
    }
    std::cout << "\n No channel active, join a channel first";
}
