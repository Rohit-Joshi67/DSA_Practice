class Solution {
public:

    bool dfs(vector<vector<char>>& board,
             string& word,
             int row,
             int col,
             int index)
    {
        // Entire word matched
        if(index == word.size())
            return true;

        // Invalid position or character mismatch
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size() ||
           board[row][col] != word[index])
        {
            return false;
        }

        // Mark current cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        bool found =
            dfs(board, word, row - 1, col, index + 1) || // up
            dfs(board, word, row + 1, col, index + 1) || // down
            dfs(board, word, row, col - 1, index + 1) || // left
            dfs(board, word, row, col + 1, index + 1);   // right

        // Backtrack
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Try starting from every cell
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};