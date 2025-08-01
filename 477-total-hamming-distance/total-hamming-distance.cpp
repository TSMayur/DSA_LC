#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total_distance = 0;
        int n = nums.size();

        // Iterate through each bit position from 0 to 30
        for (int i = 0; i < 31; ++i) {
            int set_bits_count = 0;
            
            // For the current bit 'i', count how many numbers have it set
            for (int num : nums) {
                if ((num >> i) & 1) {
                    set_bits_count++;
                }
            }
            
            int zero_bits_count = n - set_bits_count;
            
            // Add the contribution of this bit to the total distance
            total_distance += set_bits_count * zero_bits_count;
        }
        
        return total_distance;
    }
};