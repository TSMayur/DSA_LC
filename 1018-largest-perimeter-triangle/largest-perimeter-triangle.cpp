class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        if (n < 3)
            return 0;
        int  res;
        for(int i=0;i<n-2;i++){
        for (int j = i;j<i+3;j++) {
            if ((nums[i] + nums[i+1] > nums[i+2]) &&
                (nums[i+1] + nums[i+2] > nums[i]) &&
                (nums[i] + nums[i+2] > nums[i+1])) {
                res = nums[i] + nums[i+1] + nums[i+2];
                return res;
            }
        }
        }
        return 0;
    }
};