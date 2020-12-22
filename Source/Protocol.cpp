#include "Protocol.hpp"

Protocol::Protocol()
{
}
Protocol::~Protocol()
{
}
void Protocol::SendMessage(std::string message)
{
    std::cout << "\nProtocol receives: " + message;
}
void Protocol::LeaveChannel()
{
}