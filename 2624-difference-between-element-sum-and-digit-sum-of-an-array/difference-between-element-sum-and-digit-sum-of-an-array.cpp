class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0;
        int digit_sum = 0;

        for (int num : nums) {
            // Add the number itself to the element sum
            element_sum += num;
            
            // Extract and add each digit to the digit sum
            int temp_num = num;
            while (temp_num > 0) {
                digit_sum += temp_num % 10;
                temp_num /= 10;
            }
        }
        
        return abs(element_sum - digit_sum);
    }
};