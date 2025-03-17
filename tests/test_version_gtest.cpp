#define BOOST_TEST_MODULE test_version

#include <lib.h>

#include <gtest/gtest.h>
TEST(VersionTest, Positive) {
	EXPECT_TRUE(version() > 0);
}

int main() {

	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}