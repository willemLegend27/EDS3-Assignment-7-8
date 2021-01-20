#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
#include "Json.hpp"
#include <netinet/in.h>
#include <ctime>
#include <vector>
#include <thread>
#include <mutex>

class MessageHandler
{
private:
    Socket &socket;
    const time_t activity_s = 0;
    const suseconds_t activity_ms = 200;
    std::vector<nlohmann::json> IncommingMessages;
    std::thread readThread;
    std::mutex mutex;

public:
    MessageHandler(Socket &socket);
    ~MessageHandler();
    void Read();
    std::vector<nlohmann::json> GetIncommingMessages();

private:
    nlohmann::json CombineWithID(std::string currentMessage, int id);
    void StackIncommingMessage(nlohmann::json messageObject);
};

#endif