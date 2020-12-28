#include "Protocol.hpp"

Protocol::Protocol()
{
    messageHandler = new MessageHandler();
}
Protocol::~Protocol()
{
}
void Protocol::SendMessage(std::string message)
{
    messageHandler->WriteMessage(FormatToJson("message", message));
}
void Protocol::LeaveChannel()
{
}

std::string Protocol::FormatToJson(std::string type, std::string value)
{
    return "{\"type\" : \"" + type + "\" , \"value\" : \"" + value + "\"}";
}