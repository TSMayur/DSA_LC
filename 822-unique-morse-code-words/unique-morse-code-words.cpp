class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> m = {".-","-...","-.-.","-..",".","..-.","--.",
                                    "....","..",".---","-.-",".-..","--","-.",
                                    "---",".--.","--.-",".-.","...","-","..-",
                                    "...-",".--","-..-","-.--","--.."};

        unordered_set<string> t;

        for (const string& word : words) {
            string cu= "";
            for (char c : word) {
                cu=cu+m[c - 'a'];
            }
            t.insert(cu);
        }

        return t.size();
    }
};