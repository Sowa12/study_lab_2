#include <iostream>
#include <lib.h>

void out(const ipVector &v)
{
    for (const auto &i : v)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    try
    {
        ipVector ips;

        for (std::string line; std::getline(std::cin, line);)
        {
            try
            {
                strVector v = split(line, '\t');

                IPAddress ip(split(v.at(0), '.'));

                ips.insert(ip);
            }
            catch (...)
            {
            }
        }

        out(ips);
        out(filter(ips, 1));
        out(filter(ips, 46, 70));
        out(filter_any(ips, 46));

        return EXIT_SUCCESS;
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }
}