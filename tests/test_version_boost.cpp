#define BOOST_TEST_MODULE test_version

#include <lib.h>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version) {
	ipVector ips;

	auto v1 =IPAddress({"1", "2", "1", "1"});
	auto v2 =IPAddress({"1", "10", "1", "1"});

	BOOST_TEST(CustomCompare()(v1, v2) == false);
	BOOST_TEST(CustomCompare()(v2, v1) == true);
}

BOOST_AUTO_TEST_SUITE_END()