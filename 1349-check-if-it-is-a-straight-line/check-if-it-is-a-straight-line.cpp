#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) {
            return true;
        }

        // Use the first two points to define the expected slope.
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];

        // Check the slope of all other points against the first point.
        for (int i = 2; i < coordinates.size(); ++i) {
            int current_dx = coordinates[i][0] - coordinates[0][0];
            int current_dy = coordinates[i][1] - coordinates[0][1];

            // Use cross-multiplication to check for constant slope without division.
            if (dy * current_dx != dx * current_dy) {
                return false;
            }
        }

        return true;
    }
};