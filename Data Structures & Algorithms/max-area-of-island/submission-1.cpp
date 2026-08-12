class Solution {
private:
    int rows;
    int cols;

    int dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        return 1
            + dfs(r + 1, c, grid)
            + dfs(r - 1, c, grid)
            + dfs(r, c + 1, grid)
            + dfs(r, c - 1, grid);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int res = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    res = max(res, dfs(r, c, grid));
                }
            }
        }

        return res;
    }
};