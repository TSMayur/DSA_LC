class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp_dvs = dvs;
            long long multiple = 1;
            
            while ((temp_dvs << 1) <= dvd) {
                temp_dvs <<= 1;
                multiple <<= 1;
            }
            
            dvd -= temp_dvs;
            quotient += multiple;
        }
        
        bool is_negative = (dividend < 0) ^ (divisor < 0);
        if (is_negative) {
            quotient = -quotient;
        }

        return quotient;
    }
};