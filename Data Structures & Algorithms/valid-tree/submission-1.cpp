class Solution {
public: 
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) 
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if (dfs(0, -1, adj, vis))
            return false;  

        for (bool x : vis)
            if (!x)
                return false;

        return true;
    }

private:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) 
    {
        vis[node] = true;

        for (int nei : adj[node]) 
        {
            if (!vis[nei]) 
            {
                if (dfs(nei, node, adj, vis))
                    return true;
            }
            else if (nei != parent) { return true; }
            
        }

        return false;
    }

};