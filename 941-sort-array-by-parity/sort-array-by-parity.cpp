#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int w = 0; // Marks the end of the even number section

        for (int r = 0; r < nums.size(); ++r) {
            // If we find an even number
            if (nums[r] % 2 == 0) {
                // Swap it into the even section
                swap(nums[w], nums[r]);
                // Grow the even section's boundary
                w++;
            }
        }
        
        return nums;
    }
};