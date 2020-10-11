#include <gtest/gtest.h>
#include <iostream>

#include "../Example.hpp"

// TEST(ExampleTests, MAC) {
   
//     // EXPECT_TRUE(false);
//     // ASSERT_TRUE(false);

//     int a = 1, b = 2, sum = 3;
//     int expectedSum = sum + a * b;
//     EXPECT_EQ(
//         expectedSum,
//         MAC(a,b,sum)
//     ) << "MAC test passed !";
// }


TEST(VariantTests, PutVarint32) {

    uint32_t v = 111;
    std::string* s = new std::string("abc");
    PutVarint32(s, v);
    EXPECT_EQ(*s, std::string("abco")); // '0' is 111 in ASCII

    std::string* s1 = new std::string("abc");
    v = 1 << 8;
    // 10000000 00000010
    PutVarint32(s1, v);
    char* result = new char[(*s1).size() + 1];
    std::copy((*s1).begin(), (*s1).end(), result);
    EXPECT_EQ(result[3], -128);
    EXPECT_EQ(result[4], 1<<1);
}