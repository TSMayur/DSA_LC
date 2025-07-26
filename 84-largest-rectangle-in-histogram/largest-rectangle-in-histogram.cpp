class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int t = heights[st.top()];
                st.pop();
                int prev_small = st.empty() ? -1 : st.top();
                max_area = max(max_area, t * (i - prev_small - 1));
            }
            st.push(i);
        }

        int next_small = n;
        while(!st.empty()) {
            int t = heights[st.top()];
            st.pop();
            int prev_small = st.empty() ? -1 : st.top();
            max_area = max(max_area, t * (next_small - prev_small - 1));
        }

        return max_area;
    }
};