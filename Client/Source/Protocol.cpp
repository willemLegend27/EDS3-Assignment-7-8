#include "Protocol.hpp"

Protocol::Protocol()
{
    messageHandler = new MessageHandler();
}
Protocol::~Protocol()
{
}

bool Protocol::JoinChannel(std::string channelName)
{
    if (messageHandler->SendMessage(FormatToJson("join_channel", channelName)))
    {
        return true;
    }
    return false;
}

bool Protocol::LeaveChannel(std::string channelName)
{
    if (messageHandler->SendMessage(FormatToJson("leave_channel", channelName)))
    {
        return true;
    }
    return false;
}

bool Protocol::SendMessage(std::string message)
{
    if (messageHandler->SendMessage(FormatToJson("message", message)))
    {
        return true;
    }
    return false;
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
    nlohmann::json json;
    json = {{"type", type}, {"value", value}};
    return json.dump();
}