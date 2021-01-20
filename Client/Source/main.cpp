#include "UserInterface.hpp"
#include "Client.hpp"
#include "IRC.hpp"

bool clientConnected = false;

int main()
{

    UserInterface userInterface = *new UserInterface();
    std::string serverIP;
    std::string serverPort;

    while (!clientConnected)
    {
        userInterface.AskConnection(&serverIP, &serverPort);
        try
        {
            IRC irc = *new IRC(userInterface, serverIP, stoi(serverPort));
            clientConnected = true;
        }
        catch (const std::exception &e)
        {
            std::cout << "\n"
                      << e.what();
        }
    }
    return 0;
}
