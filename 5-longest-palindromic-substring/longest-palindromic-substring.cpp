class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) {
            return "";
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindromes (center is i)
            expandFromCenter(s, i, i, start, maxLen);
            // Check for even-length palindromes (center is between i and i+1)
            expandFromCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandFromCenter(const string& s, int left, int right, int& start, int& maxLen) {
        // Expand as long as pointers are in bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // After the loop, the palindrome is between the new (invalid) left and right
        int currentLen = right - left - 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
            start = left + 1;
        }
    }
};