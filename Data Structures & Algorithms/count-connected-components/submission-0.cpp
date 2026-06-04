class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<int>& vis)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        // Build graph
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);// adj[edge[0]] mai pushback edge[1] ka;
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
                count++;
            }
        }

        return count;
    }
};