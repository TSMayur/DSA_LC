class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> freq(51, 0);

        for (int i=0;i<n;i++) {
            freq[nums[i]] += 1;
        }

        int res = -1;

        if (k == 1) {
            for (int i=50;i>=0;i--) {
                if (freq[i] == 1) {
                    res = i;
                    break;
                }
            }
        }
        else if (k == n) {
            for (int i=50;i>=0;i--) {
                if (freq[i] >= 1) {
                    res = i;
                    break;
                }
            }
        }
        else if (freq[nums[0]] == 1 && freq[nums[n-1]] == 1){
            res = max(nums[0], nums[n-1]);
        }
        else if (freq[nums[0]] == 1) {
            res = nums[0];
        }
        else if (freq[nums[n-1]] == 1) {
            res = nums[n-1];
        }

        return res;
    }
};