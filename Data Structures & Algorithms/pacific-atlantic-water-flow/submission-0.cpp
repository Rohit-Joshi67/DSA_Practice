class Solution {
public:
    int rows, cols;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& vis)
    {
        vis[r][c] = 1;

        for(auto &d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];

            // invalid cell
            if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                continue;

            // already visited
            if(vis[nr][nc] == 1)
                continue;

            // reverse flow: move to same or higher height
            if(heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        // Pacific : top row
        for(int c = 0; c < cols; c++)
            dfs(0, c, heights, pacific);

        // Pacific : left column
        for(int r = 0; r < rows; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic : bottom row
        for(int c = 0; c < cols; c++)
            dfs(rows - 1, c, heights, atlantic);

        // Atlantic : right column
        for(int r = 0; r < rows; r++)
            dfs(r, cols - 1, heights, atlantic);

        vector<vector<int>> ans;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(pacific[r][c] == 1 && atlantic[r][c] == 1)
                    ans.push_back({r, c});
            }
        }

        return ans;
    }
};