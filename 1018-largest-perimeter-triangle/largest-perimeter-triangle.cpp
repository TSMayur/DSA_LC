class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort the array to easily apply the triangle inequality theorem.
        sort(nums.begin(), nums.end());

        // Iterate from the end, checking triplets.
        for (int i = nums.size() - 1; i >= 2; --i) {
            // If a <= b <= c, we only need to check if a + b > c.
            if (nums[i-2] + nums[i-1] > nums[i]) {
                // This is the first valid triangle from the largest sides,
                // so it must have the largest perimeter.
                return nums[i-2] + nums[i-1] + nums[i];
            }
        }
        
        // No valid triangle could be formed.
        return 0;
    }
};