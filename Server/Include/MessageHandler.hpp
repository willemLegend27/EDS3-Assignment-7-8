#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include "Socket.hpp"
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
    std::vector<std::string> IncommingMessages;
    std::thread readThread;
    std::mutex mutex;

public:
    MessageHandler(Socket &socket);
    ~MessageHandler();
    void Read();
    void SendMessage(int clientFD, std::string protocolMessage);
    std::vector<std::string> GetIncommingMessages();
    bool EraseFromInCommingMessages(size_t pos);

private:
    std::string CombineWithID(std::string currentMessage, int id);
    void StackIncommingMessage(std::string messageObject);
};

#endif