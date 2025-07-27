class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;
        // Only reverse half of the number to prevent overflow and optimize
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // If the number has an odd number of digits, we get rid of the middle digit using /10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};