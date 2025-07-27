class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Step 1: Create a condensed array with no consecutive duplicates.
        vector<int> unique_nums;
        if (!nums.empty()) {
            unique_nums.push_back(nums[0]);
            for (size_t i = 1; i < nums.size(); ++i) {
                if (nums[i] != unique_nums.back()) {
                    unique_nums.push_back(nums[i]);
                }
            }
        }
        
        // A hill or valley requires at least 3 distinct points.
        if (unique_nums.size() < 3) {
            return 0;
        }

        int count = 0;
        // Step 2: Iterate through the simplified array to count hills and valleys.
        // We can skip the first and last elements.
        for (size_t i = 1; i < unique_nums.size() - 1; ++i) {
            int left = unique_nums[i - 1];
            int current = unique_nums[i];
            int right = unique_nums[i + 1];

            // Check for a hill
            if (current > left && current > right) {
                count++;
            }
            // Check for a valley
            else if (current < left && current < right) {
                count++;
            }
        }

        return count;
    }
};