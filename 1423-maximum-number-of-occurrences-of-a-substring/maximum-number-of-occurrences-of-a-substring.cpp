class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> counts;
        int max_occurrences = 0;
        int n = s.length();

        // Iterate through all substrings of length minSize.
        for (int i = 0; i <= n - minSize; ++i) {
            string sub = s.substr(i, minSize);
            
            // Check if the substring is valid by counting its unique characters.
            set<char> unique_chars(sub.begin(), sub.end());
            if (unique_chars.size() <= maxLetters) {
                // If valid, increment its count and update the max.
                counts[sub]++;
                max_occurrences = max(max_occurrences, counts[sub]);
            }
        }
        
        return max_occurrences;
    }
};