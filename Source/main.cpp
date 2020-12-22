#include "UserInterface.hpp"

int main()
{
    UserInterface *userInterface = new UserInterface();

    userInterface->PrintInterface();
    while (true)
    {
        userInterface->GetChoice();
    }
    return 0;
}
