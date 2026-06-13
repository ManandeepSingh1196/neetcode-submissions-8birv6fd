class Solution {
private:
    unordered_set<int> visited;

    void dfs(vector<vector<int>>& graph, int node) 
    {
        if (!visited.emplace(node).second)
            return;

        for (int neighbour : graph[node])
            dfs(graph, neighbour);
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                components++;
                dfs(graph, i);
            }
        }

        return components;
    }
};