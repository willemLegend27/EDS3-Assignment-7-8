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
    virtual ~Channel() = default;
    std::string GetChannelName() const;

private:
};

#endif