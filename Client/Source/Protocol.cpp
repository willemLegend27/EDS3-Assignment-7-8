#include "Protocol.hpp"

Protocol::Protocol(const std::string serverIP, const int serverPort) : serverIP(serverIP), serverPort(serverPort)
{
    messageHandler = new MessageHandler(serverIP, serverPort);
}

Protocol::~Protocol()
{
    delete messageHandler;
    messageHandler = nullptr;
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

const std::vector<std::string> Protocol::GetChannelMessages()
{
    std::vector<std::string> Messages = messageHandler->GetChannelMessages();
    std::vector<nlohmann::json> JsonMessages;
    for (std::string message : Messages)
    {
        JsonMessages.push_back(nlohmann::json::parse(message));
    }
    std::cout << "Needs to convert all strings to json then pass to irc";
    std::vector<std::string> messageStrings;
    return messageStrings;
}

std::string Protocol::FormatToJson(std::string type, std::string value)
{
    nlohmann::json json;
    json = {{"type", type}, {"value", value}};
    return json.dump();
}