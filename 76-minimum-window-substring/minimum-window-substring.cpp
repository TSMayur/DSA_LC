class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(58,INT_MAX);
        int m=t.size(),n=s.size();
        int target=0;
        for(int i=0;i<m;i++)
        {
            if(freq[t[i] - 'A'] == INT_MAX)
            {
                target++;
                freq[t[i] - 'A']=0;
            }
            freq[t[i]-'A']++;
        }
        int l=0,r=0,start=-1,end=-1,size=INT_MAX,cnt=0;
        while(r<n)
        {
            if(freq[s[r] - 'A'] == INT_MAX)
            {
                r++;
                continue;
            }
            freq[s[r] - 'A']--;
            if(freq[s[r] - 'A'] == 0)
            cnt++;
            if(cnt == target)
            {
                while(freq[s[l] - 'A'] != 0)
                {
                    if(freq[s[l] - 'A'] != INT_MAX)
                    freq[s[l] - 'A']++;
                    l++;
                }
                if(r-l+1 < size)
                {
                    start=l,end=r,size=r-l+1;
                }
                freq[s[l] - 'A']++;
                l++;
                cnt--;
            }
            r++;
        }
        if(start == -1)
        return "";
        else
        return s.substr(start,end-start+1);
    }
};