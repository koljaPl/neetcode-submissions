class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int ROWS = grid.size();
        int COLS = grid[0].size();
        
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        queue<pair<int, int>> q;

        auto addGrid = [&](int r, int c) {
            if (r < 0 || r == ROWS || c < 0 || c == COLS || 
                visited[r][c] || grid[r][c] == -1) {
                return;
            }
            visited[r][c] = true;
            q.push({r, c});
        };

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int q_len = q.size();
            
            for (int i = 0; i < q_len; ++i) {
                auto [r, c] = q.front();
                q.pop();
                
                grid[r][c] = dist;

                addGrid(r + 1, c);
                addGrid(r - 1, c);
                addGrid(r, c + 1);
                addGrid(r, c - 1);
            }
            dist++;
        }
    }
};
