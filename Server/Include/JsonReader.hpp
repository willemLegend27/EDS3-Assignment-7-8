#ifndef JSONREADER_HPP
#define JSONREADER_HPP

#include "Json.hpp"

#include <algorithm>
#include <iostream>

namespace JsonReader
{
    inline bool HasKey(const nlohmann::json &input, const std::string &key)
    {
        auto iter = input.find(key);

        if (iter == input.end())
        {
            return false;
        }

        return true;
    }

    template <typename T>
    bool GetValue(const nlohmann::json &input, const std::string &key, T &out)
    {
        if (!HasKey(input, key))
        {
            return false;
        }

        try
        {
            out = input.find(key).value();
        }
        catch (const std::exception &e)
        {
            return false;
        }

        return true;
    }

} 
#endif