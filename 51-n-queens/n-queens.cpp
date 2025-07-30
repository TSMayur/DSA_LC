class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Column check
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';             // Place queen
                nQueens(board, row + 1, n, ans); // Go to next row
                board[row][j] = '.';             // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize empty board
        nQueens(board, 0, n, ans);
        return ans;
    }
};