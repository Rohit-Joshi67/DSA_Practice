class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Track digits seen in each row, column, and box
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {

                char val = board[r][c];

                // Skip empty cells
                if(val == '.')
                    continue;

                // Find 3x3 box number (0 to 8)
                int boxIndex = (r / 3) * 3 + (c / 3);

                // Duplicate found
                if(rows[r].count(val) ||
                   cols[c].count(val) ||
                   boxes[boxIndex].count(val))
                {
                    return false;
                }

                // Mark digit as seen
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxIndex].insert(val);
            }
        }

        return true;
    }
};