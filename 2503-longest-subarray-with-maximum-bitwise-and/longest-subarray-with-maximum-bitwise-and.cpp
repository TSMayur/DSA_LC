class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = 0;
        int max_length = 0;
        int current_length = 0;

        for (int num : nums) {
            if (num > max_val) {
                // We found a new, larger maximum value. Reset everything.
                max_val = num;
                current_length = 1;
                max_length = 1;
            } else if (num == max_val) {
                // Continue the current run of the maximum value.
                current_length++;
                max_length = max(max_length, current_length);
            } else { // num < max_val
                // The run of max_val is broken. Reset current length.
                current_length = 0;
            }
        }
        return max_length;
    }
};