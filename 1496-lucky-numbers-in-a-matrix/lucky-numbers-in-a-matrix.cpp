class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_min(m, INT_MAX);
        vector<int> col_max(n, 0);

        // First pass: find all row minimums and column maximums.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row_min[i] = min(row_min[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }

        vector<int> lucky_numbers;
        // Second pass: check each element against the pre-calculated values.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j]) {
                    lucky_numbers.push_back(matrix[i][j]);
                }
            }
        }

        return lucky_numbers;
    }
};