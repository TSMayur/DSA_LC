class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int speed = left + (right - left) / 2;
            long long totalTime = 0;

            for (int p : piles) {
                totalTime += (p + speed - 1) / speed;
            }

            if (totalTime <= h) {
                result = speed;
                right = speed - 1;
            } else {
                left = speed + 1;
            }
        }
        return result;
    }
};