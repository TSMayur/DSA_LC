class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LONG_MIN;
        long long second = LONG_MIN;
        long long third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        // If third remains LONG_MIN, it means a third distinct max was not found.
        // In that case, return the overall maximum (first).
        return (third == LONG_MIN) ? (int)first : (int)third;
    }
};