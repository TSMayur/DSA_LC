class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        
        vector<vector<int>> s(m, vector<int>(n));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int sum = 0;
                int count = 0;

                // Iterate through the 3x3 neighborhood
                for (int i = r - 1; i <= r + 1; ++i) {
                    for (int j = c - 1; j <= c + 1; ++j) {
                        // Check if the neighbor is within the grid boundaries
                        if (i >= 0 && i < m && j >= 0 && j < n) {
                            sum += img[i][j];
                            count++;
                        }
                    }
                }
                s[r][c] = sum / count;
            }
        }

        return s;
    }
};