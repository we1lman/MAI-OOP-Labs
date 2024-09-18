#include <iostream>
#include <string>
#include "function.h"

int main() {
    std::string input;

    std::cout << "Enter a string (lowercase letters only): ";
    std::getline(std::cin, input);

    int vowelCount = countVowels(input);

    std::cout << "Number of vowels: " << vowelCount << std::endl;

    return 0;
}
