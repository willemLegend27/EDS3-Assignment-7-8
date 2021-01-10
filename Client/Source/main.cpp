#include "UserInterface.hpp"
#include "Client.hpp"
#include "IRC.hpp"

int main()
{

    UserInterface userInterface = *new UserInterface();
    Client client = *new Client();
    IRC irc = *new IRC(userInterface, client);

    while (true)
    {
        irc.Run();
    }
    return 0;
}
