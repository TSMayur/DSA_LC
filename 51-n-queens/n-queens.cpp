class Solution {
private:
    vector<bool> cols;
    vector<bool> pos_diag;
    vector<bool> neg_diag;
    vector<vector<string>> result;
    int board_size;

    void backtrack(int row, vector<string>& board) {
        if (row == board_size) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < board_size; ++col) {
            int pos_diag_idx = row - col + board_size - 1;
            int neg_diag_idx = row + col;

            if (cols[col] || pos_diag[pos_diag_idx] || neg_diag[neg_diag_idx]) {
                continue;
            }

            // Place the queen and update state
            board[row][col] = 'Q';
            cols[col] = true;
            pos_diag[pos_diag_idx] = true;
            neg_diag[neg_diag_idx] = true;

            // Recurse to the next row
            backtrack(row + 1, board);

            // Backtrack: remove the queen and reset state
            board[row][col] = '.';
            cols[col] = false;
            pos_diag[pos_diag_idx] = false;
            neg_diag[neg_diag_idx] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board_size = n;
        vector<string> board(n, string(n, '.'));
        
        cols.resize(n, false);
        pos_diag.resize(2 * n - 1, false);
        neg_diag.resize(2 * n - 1, false);
        
        backtrack(0, board);
        return result;
    }
};