class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_map = {".-","-...","-.-.","-..",".","..-.","--.",
                                    "....","..",".---","-.-",".-..","--","-.",
                                    "---",".--.","--.-",".-.","...","-","..-",
                                    "...-",".--","-..-","-.--","--.."};

        unordered_set<string> transformations;

        for (const string& word : words) {
            string current_transformation = "";
            for (char c : word) {
                current_transformation += morse_map[c - 'a'];
            }
            transformations.insert(current_transformation);
        }

        return transformations.size();
    }
};