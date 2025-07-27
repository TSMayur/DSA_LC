class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0, right=0, maxFreq=0, maxLen=0;
        vector<int> mpp(26,0);
        while(right<n){
            mpp[s[right]-'A']++;
            maxFreq=max(maxFreq,mpp[s[right]-'A']);
            if(right-left+1 - maxFreq > k){
                mpp[s[left]-'A']--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};