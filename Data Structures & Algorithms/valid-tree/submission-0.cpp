class Solution {
public:
    bool dfs(int node, int parent,
             vector<int> adj[],
             vector<int>& vis)
    {
        vis[node] = 1;

        for(int nei : adj[node])
        {
            // unvisited node
            if(!vis[nei])
            {
                if(dfs(nei, node, adj, vis))
                    return true; // cycle found
            }
            // visited but not parent
            else if(nei != parent)
            {
                return true; // cycle found
            }
        }

        return false; // no cycle
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // tree must have exactly n-1 edges
        if(edges.size() != n - 1)
            return false;

        vector<int> adj[n];

        for(auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        // cycle check
        if(dfs(0, -1, adj, vis))
            return false;

        // connected check
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
                return false;
        }

        return true;
    }
};