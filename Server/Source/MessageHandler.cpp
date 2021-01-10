#include "MessageHandler.hpp"
#include <thread>

#include <iostream>

MessageHandler::MessageHandler(Socket &socket) : socket(socket)
{
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::Read()
{
    while (true)
    {
        fd_set readFds;
        int nrSockets = this->socket.GetActivity(this->activity_s, this->activity_s, readFds);

        if (nrSockets > 0)
        {
            if (FD_ISSET(this->socket.GetSocketFD(), &readFds))
            {
                this->socket.AcceptConnection();
                std::cout << "connected\n";
            }
            else
            {
                for (auto clientFD : this->socket.GetConnections())
                {
                    if (FD_ISSET(clientFD, &readFds))
                    {
                        std::string response;
                        bool success = this->socket.GetMessage(clientFD, response);

                        if (!success || response == "disc")
                        {
                            this->socket.Disconnect(clientFD);
                            std::cout << "disconnected\n";
                        }
                        else
                        {
                            std::cout << "received: " << response << '\n';
                            this->socket.SendMessage(clientFD, "received your message\n");
                        }
                    }
                }
            }
        }
        else
        {
            //do something else
        }
    }
}