class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> min_freq(26, 101); // Initialize with a value > max possible freq

        // Find the minimum frequency for each character across all words
        for (const string& word : words) {
            vector<int> current_freq(26, 0);
            for (char c : word) {
                current_freq[c - 'a']++;
            }
            
            for (int i = 0; i < 26; ++i) {
                min_freq[i] = min(min_freq[i], current_freq[i]);
            }
        }

        // Build the result vector from the final minimum frequencies
        vector<string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < min_freq[i]; ++j) {
                result.push_back(string(1, 'a' + i));
            }
        }

        return result;
    }
};