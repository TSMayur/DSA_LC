#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital_count = 0;
        for (char c : word) {
            if (isupper(c)) {
                capital_count++;
            }
        }
        return capital_count == word.length() || 
               capital_count == 0 ||
               (capital_count == 1 && isupper(word[0]));
    }
};