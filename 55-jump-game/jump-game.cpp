class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // If the current index is greater than the farthest we can reach,
            // it's impossible to continue.
            if (i > max_reachable) {
                return false;
            }
            
            // Update the farthest reachable index from the current position.
            max_reachable = max(max_reachable, i + nums[i]);
            
            // An optional optimization: if we can already reach the end,
            // we can stop early.
            if (max_reachable >= n - 1) {
                return true;
            }
        }
        
        // If the loop completes, it means the last index was reachable.
        return true;
    }
};