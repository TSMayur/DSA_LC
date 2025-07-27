class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0;
        if (m > n) return -1;

        for (int i = 0; i <= n - m; ++i) {
            // Check for a match starting at index i
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If the inner loop completed, we found a full match
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};