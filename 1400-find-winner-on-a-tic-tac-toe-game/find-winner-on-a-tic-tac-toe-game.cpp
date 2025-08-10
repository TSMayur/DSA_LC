class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diag1 = 0;
        int diag2 = 0;
        
        int player = 1; // Start with Player A (+1)

        for (const auto& move : moves) {
            int r = move[0];
            int c = move[1];

            rows[r] += player;
            cols[c] += player;
            if (r == c) {
                diag1 += player;
            }
            if (r + c == 2) {
                diag2 += player;
            }

            // Check if the current player has won
            if (abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag1) == 3 || abs(diag2) == 3) {
                return (player == 1) ? "A" : "B";
            }

            // Switch to the other player for the next turn
            player *= -1;
        }

        // If no winner after all moves, check for Draw or Pending
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};