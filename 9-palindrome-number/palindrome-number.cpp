class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int l = str.size()-1;
        for(int i = 0 ;i<str.size()/2 ; i++){
            if(str[i] != str[l-i]) return false;
        }
        return true;
    }
};