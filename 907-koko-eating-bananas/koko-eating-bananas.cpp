class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(high>low){
            int mid=low+(high-low)/2;
            int count=0;
            for(int it:piles){
                count+=(it+mid-1)/mid;
            }
            if(count>h) low=mid+1;
            else high=mid;
        }

        return low;
    }
};