class Solution {
private:
    int INF = 2147483647;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;

        int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    dfs(0, i, j, grid);

    }

private:
    void dfs(int distance, int x, int y, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (x < 0 || x >= m || y < 0 || y >= n)
            return;

        if (grid[x][y] == -1)
            return;

        if (grid[x][y] < distance)
            return;

        grid[x][y] = distance;

        dfs(distance + 1, x + 1, y, grid);
        dfs(distance + 1, x - 1, y, grid);
        dfs(distance + 1, x, y + 1, grid);
        dfs(distance + 1, x, y - 1, grid);
    }
};