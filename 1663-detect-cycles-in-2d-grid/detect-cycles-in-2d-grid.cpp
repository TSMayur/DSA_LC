#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    // Directions: right, left, down, up
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    bool dfs(vector<vector<char>>& grid, int r, int c, int parent_r, int parent_c) {
        visited[r][c] = true;
        char target_char = grid[r][c];

        for (int i = 0; i < 4; ++i) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            // Check boundaries
            if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n) {
                continue;
            }

            // Don't go back to the parent immediately
            if (next_r == parent_r && next_c == parent_c) {
                continue;
            }

            // Check for same character
            if (grid[next_r][next_c] == target_char) {
                // If this neighbor has been visited, we found a cycle
                if (visited[next_r][next_c]) {
                    return true;
                }
                // Recurse
                if (dfs(grid, next_r, next_c, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};