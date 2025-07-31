#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        // Create a set of characters from the string.
        // The set will automatically handle duplicates, storing only one of each character.
        unordered_set<char> unique_chars(s.begin(), s.end());
        
        // The size of the set is the number of unique characters.
        return unique_chars.size();
    }
};