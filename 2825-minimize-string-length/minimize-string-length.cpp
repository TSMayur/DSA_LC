class Solution {
public:
    int minimizedStringLength(string S){
        int f[26]={0},count=0;
        for(const char & c : S) f[c-'a']++;
        for(int i=0;i<26;i++) if(f[i]>=1) count++;
        return count;
    }
};
