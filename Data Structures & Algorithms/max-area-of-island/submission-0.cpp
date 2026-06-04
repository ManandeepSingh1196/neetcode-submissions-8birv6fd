class Solution {
private: 
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
            return 0;

        grid[row][col] = 0;
        int result = 1;

        return result + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) + dfs (grid, row, col + 1) + dfs (grid, row, col - 1);

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    area = max(area, dfs(grid, r, c));
                }
            }
        }

        return area;
    }
};
