class Solution {
public:

    bool dfs(int node,
             vector<int> adj[],
             vector<int>& state)
    {
        // current DFS path me hai -> cycle
        if(state[node] == 1)
            return true;

        // already completely processed
        if(state[node] == 2)
            return false;

        // mark as visiting
        state[node] = 1;

        for(int nei : adj[node])
        {
            if(dfs(nei, adj, state))
                return true;
        }

        // mark as fully processed
        state[node] = 2;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites)
    {
        vector<int> adj[numCourses];

        // build graph
        for(auto& it : prerequisites)
        {
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }

        // 0 = unvisited
        // 1 = visiting
        // 2 = visited
        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(dfs(i, adj, state))
                return false;
        }

        return true;
    }
};