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

    inline bool ParseJson(const std::string &message, nlohmann::json &out)
    {
        // better json parse implementation that isolates the json from noise
        auto begin = message.find('{');
        auto end = message.find_last_of('}');

        if (begin == std::string::npos || end == std::string::npos)
        {
            return false;
        }
        else
        {
            std::string jsonString = message.substr(begin, end - begin + 1);

            try
            {
                out = nlohmann::json::parse(jsonString);
                return true;
            }
            catch (const std::exception &e)
            {
                return false;
            }
        }
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

} // namespace JsonReader

#endif