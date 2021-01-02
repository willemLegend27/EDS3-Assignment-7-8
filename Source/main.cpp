#include "UserInterface.hpp"

int main()
{
    UserInterface *userInterface = new UserInterface();

    userInterface->PrintInterface();
    while (true)
    {
        userInterface->GetChoice();
        std::cout << "\n================================";
    }
    return 0;
}
