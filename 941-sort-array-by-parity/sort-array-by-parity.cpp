class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int wp = 0; // Marks the end of the even number section

        for (int rp = 0; rp < nums.size(); ++rp) {
            // If we find an even number
            if (nums[rp] % 2 == 0) {
                // Swap it into the even section
                swap(nums[wp], nums[rp]);
                // Grow the even section's boundary
                wp++;
            }
        }
        
        return nums;
    }
};