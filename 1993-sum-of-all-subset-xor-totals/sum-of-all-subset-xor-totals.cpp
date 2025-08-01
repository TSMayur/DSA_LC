#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int or_total = 0;
        for (int num : nums) {
            or_total |= num;
        }

        // The multiplier is 2^(n-1), which can be calculated
        // efficiently using a left bit shift.
        return or_total << (nums.size() - 1);
    }
};