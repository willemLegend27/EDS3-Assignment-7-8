#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>

class Channel
{
private:
    std::string name;

public:
    Channel();
    ~Channel() = default;
    std::string GetChannelName();

private:
};

#endif