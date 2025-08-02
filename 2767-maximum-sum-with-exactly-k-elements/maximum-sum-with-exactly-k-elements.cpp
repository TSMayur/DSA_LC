class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());     
        int score = 0;
        for (int i = 0; i < k; ++i) {
            score += max_val;
            max_val++;
        }
        
        return score;
    }
};