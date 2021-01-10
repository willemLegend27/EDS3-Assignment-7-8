#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
#include <netinet/in.h>
#include <ctime>

class MessageHandler
{
private:
    Socket &socket;
    const time_t activity_s = 0;
    const suseconds_t activity_ms = 200;

public:
    MessageHandler(Socket &socket);
    ~MessageHandler();

    void Read();

private:
};

#endif