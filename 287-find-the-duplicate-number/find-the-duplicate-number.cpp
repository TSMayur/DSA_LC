class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        if (nums.size() == 2)
            return nums[0];
        else
            return Secret(nums);
    }
private:
    int Secret(vector<int>& nums)
    {
        int s = nums[0];
        int f = nums[0];
        s = nums[s];
        f = nums[nums[f]];
        while (s != f)
        {
            s = nums[s];
            f = nums[nums[f]];
        }
        s = nums[0];
        while (s != f)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};