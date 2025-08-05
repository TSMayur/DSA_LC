class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find the index of the first occurrence of 'ch'.
        size_t found_pos = word.find(ch);
        
        // If the character was found...
        if (found_pos != string::npos) {
            // ...reverse the substring from the beginning to the found position.
            reverse(word.begin(), word.begin() + found_pos + 1);
        }
        
        return word;
    }
};