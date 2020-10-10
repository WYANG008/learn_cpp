#include <gtest/gtest.h>
#include "../Example.hpp"

TEST(ExampleTests, MAC) {
   
    // EXPECT_TRUE(false);
    // ASSERT_TRUE(false);

    int a = 1, b = 2, sum = 3;
    int expectedSum = sum + a * b;
    EXPECT_EQ(
        expectedSum,
        MAC(a,b,sum)
    ) << "MAC test passed !";
}

TEST(ExampleTests2, Square) {
    EXPECT_EQ(true, true);
}