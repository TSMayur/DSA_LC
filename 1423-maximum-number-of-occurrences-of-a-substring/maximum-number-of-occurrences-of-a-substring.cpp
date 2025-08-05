class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //the main trick here is that if any substr exists s.t. 
        //number of unique characters in the substring must be less than or equal to maxLetters then there will always
       //substr of len = minlen that also satisfies the condition and we have to find no of occurences for this len only bec smaller len will always produce more repetitions than bigger ones
        //so -> for all substr of len = minlen, find substr with max no of occurences & satisfying the cond
        int n = s.length();
        int unicount = 0;
        vector<int> freq(26, 0);
        unordered_map<string, int> mp;
        int left = 0;
        for(int right = 0; right < n; right++){
            if(++freq[s[right]-'a'] == 1) unicount++;
            if(right - left + 1 > minSize){
                if(--freq[s[left]-'a'] == 0) unicount--;
                left++;
            }
            if(right - left + 1 == minSize && unicount <= maxLetters){
                string temp = s.substr(left, minSize);
                mp[temp]++;
            }
        }
        int ans = 0;
        for(auto& [i, j]: mp) ans=max(ans, j);
        return ans;
    }
};