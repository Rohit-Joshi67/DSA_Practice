class Solution {
public:

    int numIslands(vector<vector<char>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int islands = 0;

        vector<pair<int,int>> directions = {
            {1,0},   // Down
            {-1,0},  // Up
            {0,1},   // Right
            {0,-1}   // Left
        };

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                // Found a new island
                if(grid[row][col] == '1')
                {
                    islands++;

                    queue<pair<int,int>> q;

                    q.push({row, col});

                    // Mark visited immediately
                    grid[row][col] = '0';

                    while(!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        for(auto& dir : directions)
                        {
                            int nr = r + dir.first;
                            int nc = c + dir.second;

                            // Valid land cell
                            if(nr >= 0 && nr < rows &&
                               nc >= 0 && nc < cols &&
                               grid[nr][nc] == '1')
                            {
                                q.push({nr, nc});

                                // Mark visited so it won't be added again
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};