#pragma once

#include <vector>
#include <string>

template <typename T>
std::string to_str(std::vector<T> data)
{
    std::string ret = "";
    for (T d : data)
    {
        if (ret.size())
        {
            ret += ", ";
        }
        ret += std::to_string(d);
    }
    return "(" + ret + ")";
}