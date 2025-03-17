#define BOOST_TEST_MODULE test_version

#include <lib.h>

#include <gtest/gtest.h>
TEST(VersionTest, Positive)
{
	ipVector ips;

	auto v1 = IPAddress({"1", "2", "1", "1"});
	auto v2 = IPAddress({"1", "10", "1", "1"});

	EXPECT_TRUE(CustomCompare()(v2, v1));
}

TEST(VersionTest, Negative)
{
	ipVector ips;

	auto v1 = IPAddress({"1", "2", "1", "1"});
	auto v2 = IPAddress({"1", "10", "1", "1"});

	EXPECT_FALSE(CustomCompare()(v1, v2));
}

int main()
{

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}