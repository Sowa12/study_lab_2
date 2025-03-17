#include <iostream>
#include <lib.h>

int main()
{
    try
    {
        ipVector ips;

        for (std::string line; std::getline(std::cin, line);)
        {
            try {
            strVector v = split(line, '\t');

            IPAddress ip(split(v.at(0), '.'));

            ips.insert(ip);
            } catch(...) {

            }
        }
        
        for (const auto& i : ips) {
            std::cout << i << std::endl;
        }

        const auto ip_with_part_1 = filter(ips, 1);

        for (const auto& i : ip_with_part_1) {
            std::cout << i << std::endl;
        }

        const auto ip_with_part_46_70 = filter(ips, 46, 70);

        for (const auto& i : ip_with_part_46_70) {
            std::cout << i << std::endl;
        }

        const auto ip_with_any_part_46 = filter_any(ips, 46);

        for (const auto& i : ip_with_any_part_46) {
            std::cout << i << std::endl;
        }

        return EXIT_SUCCESS;
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }
}