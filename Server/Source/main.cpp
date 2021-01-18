#include "MessageHandler.hpp"
#include "Server.hpp"

int main()
{
    Socket socket(5001, 20);
    MessageHandler messageHandler(socket);
    Server server(messageHandler);
    server.ReadSocketActivity();
}