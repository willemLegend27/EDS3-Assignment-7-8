#include "IRC.hpp"

IRC::IRC()
{
    protocol = new Protocol();
}

IRC::~IRC()
{
}

void IRC::SendMessage(std::string message)
{
    protocol->SendMessage(message);
}

void IRC::JoinChannel(std::string channelName)
{
    protocol->JoinChannel(channelName);
}

void IRC::LeaveChannel()
{
}

void IRC::GetChannelMessages()
{
}