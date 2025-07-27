class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::array<int, 256> store;
    store.fill(-1);
    int start = 0, end = 0, n = s.size(), res = 0;
    for (int end = 0; end < n; ++ end) {
      char c = s[end];
      if (store[c] != -1) {
        start = std::max(start, store[c]);
      }
      res = std::max(res, end - start + 1);
      store[c] = end + 1;
    }
    return res;
  }
};