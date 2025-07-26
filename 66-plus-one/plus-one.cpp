class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            digits[i]++;
            
            // If the digit is less than 10, there's no carry, so we're done.
            if (digits[i] < 10) {
                return digits;
            }
            
            // Otherwise, there is a carry. Set the digit to 0 and continue.
            digits[i] = 0;
        }

        // If the loop completes, it means the original number was all 9s.
        // We need to insert a 1 at the beginning.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};