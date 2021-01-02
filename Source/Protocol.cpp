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

void Protocol::JoinChannel(std::string channelName)
{
    messageHandler->WriteMessage(FormatToJson("join channel", channelName));
}

void Protocol::LeaveChannel()
{
}

std::vector<nlohmann::json> Protocol::GetChannelMessages()
{
    //std::vector<std::string> *messages = messageHandler->GetChannelMessages();
    std::cout << "Needs to convert all strings to json then pass to irc";
}

std::string Protocol::FormatToJson(std::string type, std::string value)
{
    return "{\"type\" : \"" + type + "\" , \"value\" : \"" + value + "\"}";
}