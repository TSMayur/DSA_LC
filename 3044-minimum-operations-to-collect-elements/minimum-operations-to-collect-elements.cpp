class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> found;
        int operations = 0;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            operations++;
            
            if (nums[i] <= k) {
                found.insert(nums[i]);
            }
            
            if (found.size() == k) {
                return operations;
            }
        }
        
        return operations; 
    }
};