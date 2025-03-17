#include <lib.h>
#include <sstream>

#include "version.h"

std::ostream &operator<<(std::ostream &stream, const IPAddress &v)
{
    std::string str;

    for (auto &i : v._part)
    {
        str += std::to_string(i) + ".";
    }

    str.pop_back();

    stream << str;

    return stream;
}

ipVector filter(const ipVector &src, const uint8_t &part)
{
    ipVector result;

    for (const auto &i : src)
    {
        if (i._part[0] == part)
            result.insert(i);
    }

    return result;
}

ipVector filter(const ipVector &src, const uint8_t &part1, const uint8_t &part2)
{
    ipVector result;

    for (const auto &i : src)
    {
        if (i._part[0] == part1 && i._part[1] == part2)
            result.insert(i);
    }

    return result;
}

ipVector filter_any(const ipVector &src, const uint8_t &part)
{
    ipVector result;

    for (const auto &i : src)
    {
        for (const auto &j : i._part)
        {
            if (j == part) {
                result.insert(i);
                break;
            }
        }
    }

    return result;
}

strVector split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

IPAddress::IPAddress(const IPAddress &other)
{
    for (size_t i = 0; i < _part.size(); ++i)
    {
        _part[i] = other._part[i];
    }
}

IPAddress &IPAddress::operator<<(const strVector &v)
{
    try
    {
        for (size_t i = 0; i < _part.size(); ++i)
        {
            auto tmp = std::stoi(v[i]);
            if (tmp > 255 or tmp < 0) {
                throw "Неккоректное значение!";
            }
            _part[i] = tmp;
        }
    }
    catch (...)
    {
        throw;
    }

    return *this;
}

bool CustomCompare::operator()(const IPAddress &left, const IPAddress &right)
{
    uint32_t l = 0;
    uint32_t r = 0;

    for (size_t i = 0; i < left._part.size(); ++i)
    {
        l = (l << 8) | left._part[i];
        r = (r << 8) | right._part[i];
    }

    return l > r;
}
