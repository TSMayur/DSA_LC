class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_mins(m, INT_MAX);
        vector<int> col_maxs(n, 0);

        // First pass: find all row minimums and column maximums.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_mins[i] = min(row_mins[i], matrix[i][j]);
                col_maxs[j] = max(col_maxs[j], matrix[i][j]);
            }
        }

        vector<int> lucky_numbers;
        // Second pass: check each element against the pre-calculated values.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == row_mins[i] && matrix[i][j] == col_maxs[j]) {
                    lucky_numbers.push_back(matrix[i][j]);
                }
            }
        }

        return lucky_numbers;
    }
};