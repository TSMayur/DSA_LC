class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;

        // Step 1: Find the pivot from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If a pivot is found
        if (i >= 0) {
            // Step 2: Find the smallest element on the right > pivot
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the suffix (works for both cases)
        reverse(nums.begin() + i + 1, nums.end());
    }
};