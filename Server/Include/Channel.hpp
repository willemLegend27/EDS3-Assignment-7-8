#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"
#include <iostream>
#include <vector>

class Channel
{
private:
    std::string name;
    std::vector<Client> Clients;

public:
    Channel();
    ~Channel() = default;

private:
};

#endif