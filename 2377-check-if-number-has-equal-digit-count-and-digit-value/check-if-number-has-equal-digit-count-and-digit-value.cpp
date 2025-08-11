class Solution {
public:
    bool digitCount(string num) {
        // Use a vector as a frequency map for digits 0-9.
        vector<int> counts(10, 0);
        
        // First pass: count the actual frequency of each digit in the string.
        for (char c : num) {
            counts[c - '0']++;
        }

        // Second pass: verify the condition for each index.
        for (int i = 0; i < num.length(); ++i) {
            // The required count of digit 'i' is given by the character num[i].
            int required_count = num[i] - '0';
            
            // The actual count of digit 'i' is what we stored in our map.
            int actual_count = counts[i];

            if (actual_count != required_count) {
                return false;
            }
        }
        
        return true;
    }
};