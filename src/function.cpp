#include "function.h"
#include <string>
#include <unordered_set>

int countVowels(const std::string& input) {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;

    for (char ch : input) {
        if (vowels.find(ch) != vowels.end()) {
            count++;
        }
    }

    return count;
}
