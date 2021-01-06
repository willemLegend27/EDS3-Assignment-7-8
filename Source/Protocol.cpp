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
    messageHandler->SendMessage(FormatToJson("message", message));
}

void Protocol::JoinChannel(std::string channelName)
{
    messageHandler->SendMessage(FormatToJson("join channel", channelName));
}

void Protocol::LeaveChannel()
{
}

std::vector<nlohmann::json> Protocol::GetChannelMessages()
{
    //std::vector<std::string> *messages = messageHandler->GetChannelMessages();
    std::cout << "Needs to convert all strings to json then pass to irc";
    std::vector<nlohmann::json> a;
    return a;
}

std::string Protocol::FormatToJson(std::string type, std::string value)
{
    return "{\"type\" : \"" + type + "\" , \"value\" : \"" + value + "\"}";
}