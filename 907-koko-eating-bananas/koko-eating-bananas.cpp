class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) {
            return 0;
        }
        long long left = 1;
        long long right = 1;
        for (int p: piles) {
            right = max(right, (long long)p);
        }
        long long res = right + 1;
        while (left <= right) {
            long long k = left + (right - left) / 2;
            long long days = helper(piles, k);
            if (days > h) {
                left = k + 1;
            } else {
                res = min(res, k);
                right = k - 1;
            }
        }
        return res;

    }
    long long helper(vector<int>& piles, long long k) {
        long long days = 0;
        for (int p: piles) {
            days += (long long)p / k + (p % k == 0 ? 0 : 1);
        }
        return days;
    }
};