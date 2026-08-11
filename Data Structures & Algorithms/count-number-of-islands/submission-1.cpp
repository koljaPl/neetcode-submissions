class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        const int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        auto bfs = [&](int startRow, int startCol) {
            queue<pair<int, int>> q;

            q.push({startRow, startCol});
            visited[startRow][startCol] = true;

            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& direction : directions) {
                    int currRow = row + direction[0];
                    int currCol = col + direction[1];

                    if (currRow >= 0 && currRow < n &&
                        currCol >= 0 && currCol < m &&
                        grid[currRow][currCol] == '1' &&
                        !visited[currRow][currCol]) {

                        visited[currRow][currCol] = true;
                        q.push({currRow, currCol});
                    }
                }
            }
        };

        int islands = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    bfs(row, col);
                    islands++;
                }
            }
        }

        return islands;
    }
};