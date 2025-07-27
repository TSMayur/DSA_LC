class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1_counts(26, 0);
        vector<int> window_counts(26, 0);

        // Populate maps for the initial window
        for (int i = 0; i < s1.length(); ++i) {
            s1_counts[s1[i] - 'a']++;
            window_counts[s2[i] - 'a']++;
        }

        // Check if the initial window is a match
        if (s1_counts == window_counts) {
            return true;
        }

        // Slide the window across the rest of s2
        for (int i = s1.length(); i < s2.length(); ++i) {
            // Add the new character entering the window
            window_counts[s2[i] - 'a']++;
            // Remove the character leaving the window
            window_counts[s2[i - s1.length()] - 'a']--;

            // Check for a match after sliding
            if (s1_counts == window_counts) {
                return true;
            }
        }

        return false;
    }
};