#include <gtest/gtest.h>
#include <iostream>

#include "../Variant.hpp"

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

TEST(VariantTests, GetVarint32) {
    std::string data = "a";
    leveldb::Slice* input = new leveldb::Slice(data);
    uint32_t* value;
    bool result = GetVarint32(input, value);
    EXPECT_TRUE(result);
    EXPECT_EQ(*value, 'a');

    
    char myword[] = { -128, -1, 97, '\0' }; // 10000000 11111111 01100001('a')
    std::string data1 =  std::string(myword);
    leveldb::Slice* input1 = new leveldb::Slice(data1);
    uint32_t* value1;
    // 00000000 00011000 01111111 10000000 = 1605504
    bool result1 = GetVarint32(input1, value1);
    EXPECT_TRUE(result1);
    EXPECT_EQ(*value1, 1605504);
}
