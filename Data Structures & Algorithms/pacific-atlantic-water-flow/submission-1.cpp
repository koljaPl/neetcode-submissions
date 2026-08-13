class Solution {
private:
    int rows;
    int cols;

    vector<vector<int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    void dfs(
        int r,
        int c,
        vector<vector<int>>& heights,
        vector<vector<bool>>& visited,
        int previousHeight
    ) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (visited[r][c] || heights[r][c] < previousHeight) {
            return;
        }

        visited[r][c] = true;

        for (auto& direction : directions) {
            int newR = r + direction[0];
            int newC = c + direction[1];

            dfs(
                newR,
                newC,
                heights,
                visited,
                heights[r][c]
            );
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacificVisited(
            rows,
            vector<bool>(cols, false)
        );

        vector<vector<bool>> atlanticVisited(
            rows,
            vector<bool>(cols, false)
        );

        for (int c = 0; c < cols; ++c) {
            dfs(
                0,
                c,
                heights,
                pacificVisited,
                heights[0][c]
            );

            dfs(
                rows - 1,
                c,
                heights,
                atlanticVisited,
                heights[rows - 1][c]
            );
        }

        for (int r = 0; r < rows; ++r) {
            dfs(
                r,
                0,
                heights,
                pacificVisited,
                heights[r][0]
            );

            dfs(
                r,
                cols - 1,
                heights,
                atlanticVisited,
                heights[r][cols - 1]
            );
        }

        vector<vector<int>> result;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pacificVisited[r][c] &&
                    atlanticVisited[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};