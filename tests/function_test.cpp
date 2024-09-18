#include <gtest/gtest.h>
#include <function.h>

TEST(CountVowelsTest, EmptyString) {
    std::string input = "";
    
    int result = countVowels(input);

    EXPECT_EQ(result, 0);
}

TEST(CountVowelsTest, NoVowels) {
    std::string input = "bcdfg";

    int result = countVowels(input);

    EXPECT_EQ(result, 0);
}

TEST(CountVowelsTest, OnlyVowels) {
    std::string input = "aeiou";

    int result = countVowels(input);

    EXPECT_EQ(result, 5);
}

TEST(CountVowelsTest, MixedVowelsAndConsonants) {
    std::string input = "hello world";

    int result = countVowels(input);

    EXPECT_EQ(result, 3);
}

TEST(CountVowelsTest, VowelsWithSpaces) {
    std::string input = "a e i o u";

    int result = countVowels(input);

    EXPECT_EQ(result, 5);
}

TEST(CountVowelsTest, LongStringWithRepeatedVowels) {
    std::string input = "aaaaaaaaaa";

    int result = countVowels(input);

    EXPECT_EQ(result, 10);
}

TEST(CountVowelsTest, ConsonantsWithSpaces) {
    std::string input = "b c d f g";

    int result = countVowels(input);

    EXPECT_EQ(result, 0);
}

TEST(CountVowelsTest, MixedVowelsAndConsonantsNoSpaces) {
    std::string input = "qwerty";

    int result = countVowels(input);

    EXPECT_EQ(result, 1);
}

TEST(CountVowelsTest, SingleVowel) {
    std::string input = "u";

    int result = countVowels(input);

    EXPECT_EQ(result, 1);
}

TEST(CountVowelsTest, EqualVowelsAndConsonants) {
    std::string input = "aeiobcdfg";

    int result = countVowels(input);

    EXPECT_EQ(result, 4);
}
