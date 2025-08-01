class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;

        for (char c : s) {
            if (st.empty() || st.back().first != c) {
                st.push_back({c, 1});
            } else {
                st.back().second++;
            }

            if (st.back().second == k) {
                st.pop_back();
            }
        }

        string result = "";
        for (const auto& p : st) {
            result.append(p.second, p.first);
        }

        return result;
    }
};