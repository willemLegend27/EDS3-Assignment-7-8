#include "UserInterface.hpp"

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
    std::cout << "\n(1) Join channel";
    std::cout << "\n(2) Send message";
    std::cout << "\n(3) Exit";
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
        break;
    case 2:
        std::string message;
        std::cout << "\nInput message to send: ";
        getline(std::cin, message);
        std::cout << "\nInput message: " + message;
        client->Read("s{" + message + "}");
        break;
    }
}
