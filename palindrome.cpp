// palindrome.cpp
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    if (str.empty()) return true;

    std::string cleanStr;
    // Remove non-alphanumeric characters and convert to lowercase
    for (char c : str) {
        if (std::isalnum(c)) {
            cleanStr += std::tolower(c);
        }
    }

    // Check if the string reads the same forward and backward
    std::string reversedStr = cleanStr;
    std::reverse(reversedStr.begin(), reversedStr.end());

    return cleanStr == reversedStr;
}
