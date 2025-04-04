#include <gtest/gtest.h>
#include <string>

// Declare the function from palindrome.cpp
extern bool isPalindrome(const std::string& str);

// Test suite for the isPalindrome function
TEST(PalindromeTest, BasicCases) {
    // Test empty string
    EXPECT_TRUE(isPalindrome(""));

    // Test single character
    EXPECT_TRUE(isPalindrome("a"));

    // Test simple palindromes
    EXPECT_TRUE(isPalindrome("aba"));
    EXPECT_TRUE(isPalindrome("racecar"));

    // Test non-palindromes
    EXPECT_FALSE(isPalindrome("hello"));
    EXPECT_FALSE(isPalindrome("world"));
}

TEST(PalindromeTest, CaseInsensitive) {
    // Test case insensitivity
    EXPECT_TRUE(isPalindrome("Racecar"));
    EXPECT_TRUE(isPalindrome("RaceCar"));
    EXPECT_TRUE(isPalindrome("A man a plan a canal Panama"));
}

TEST(PalindromeTest, IgnoreNonAlphanumeric) {
    // Test ignoring non-alphanumeric characters
    EXPECT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_TRUE(isPalindrome("Race car!"));
    EXPECT_TRUE(isPalindrome("No 'x' in Nixon"));
}

// Additional test cases
TEST(PalindromeTest, EdgeCases) {
    // Test with numbers
    EXPECT_TRUE(isPalindrome("12321"));
    EXPECT_FALSE(isPalindrome("12345"));

    // Test with mixed alphanumeric
    EXPECT_TRUE(isPalindrome("a1b2c3c2b1a"));
    EXPECT_FALSE(isPalindrome("a1b2c3b2a1"));

    // Test with spaces
    EXPECT_TRUE(isPalindrome("never odd or even"));
    EXPECT_FALSE(isPalindrome("not a palindrome"));
}
