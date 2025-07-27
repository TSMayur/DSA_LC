class Solution {
public:
    bool isPalindrome(int x) {
        // Handle edge cases: negative numbers and numbers ending in 0 (but not 0 itself).
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // For even-length numbers, x == revertedNumber.
        // For odd-length numbers, we discard the middle digit with revertedNumber / 10.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};