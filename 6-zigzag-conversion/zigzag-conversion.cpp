class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if numRows is 1, the output is the same as the input.
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the input string
        for (char c : s) {
            rows[currentRow] += c;
            
            // If we are at the top or bottom row, flip the direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all the row strings into one
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        
        return result;
    }
};