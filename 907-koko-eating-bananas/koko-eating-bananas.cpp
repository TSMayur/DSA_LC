class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i : piles){
            r = max(i, r);
        }

        while(l < r){
            int m = l + (r - l) / 2;
            
            int cnt = 0;
            for(int i : piles){
                cnt += (long(i) + long(m) - 1) / m; 
            }

            if(cnt <= h)r = m;
            else l = m + 1;
        }
        return l;
    }
};