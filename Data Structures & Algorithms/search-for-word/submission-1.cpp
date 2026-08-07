class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(
            rows,
            vector<bool>(cols, false)
        );

        function<bool(int, int, int)> dfs = [&](int r, int c, int i) -> bool {
            if (i == word.size()) {
                return true;
            }

            if (r < 0 || c < 0 ||
                r >= rows || c >= cols ||
                visited[r][c] ||
                board[r][c] != word[i]) {
                return false;
            }

            visited[r][c] = true;

            bool res =
                dfs(r + 1, c, i + 1) ||
                dfs(r - 1, c, i + 1) ||
                dfs(r, c + 1, i + 1) ||
                dfs(r, c - 1, i + 1);

            visited[r][c] = false;

            return res;
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};