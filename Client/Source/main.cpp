#include "UserInterface.hpp"
#include "Client.hpp"
#include "IRC.hpp"

int main()
{

    UserInterface userInterface = *new UserInterface();
    Client client = *new Client("192.168.1.160", 5001);
    IRC irc = *new IRC(userInterface, client);

    while (true)
    {
        irc.Run();
    }
    return 0;
}
