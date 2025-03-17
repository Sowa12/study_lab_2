#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <ostream>
#include <array>
#include <set>

constexpr uint8_t COUNT_IP_PART = 4;

using strVector = std::vector<std::string>;

struct IPAddress {
    std::array<uint8_t, COUNT_IP_PART> _part;

    IPAddress(const strVector& v) {
        try {
        *this << v;
        } catch(...) {
            throw;
        }
    }

    IPAddress(const IPAddress& other);

    IPAddress& operator<<(const strVector&);
};

std::ostream& operator<<(std::ostream& stream, const IPAddress& v);

struct CustomCompare {
    bool operator()(const IPAddress& left, const IPAddress& right);
};

strVector split(const std::string &str, char d);

using ipVector = std::multiset<IPAddress, CustomCompare>;

ipVector filter(const ipVector& src, const uint8_t&);
ipVector filter(const ipVector& src, const uint8_t&, const uint8_t&);
ipVector filter_any(const ipVector& src, const uint8_t&);
