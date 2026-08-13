class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        auto dfs = [&](auto&& self, int row, int col) -> void {
            if (row < 0 || col < 0 || row >= rows || col >= cols) {
                return;
            }

            if (board[row][col] != 'O') {
                return;
            }

            board[row][col] = '#';

            self(self, row + 1, col);
            self(self, row - 1, col);
            self(self, row, col + 1);
            self(self, row, col - 1);
        };

        for (int row = 0; row < rows; ++row) {
            dfs(dfs, row, 0);
            dfs(dfs, row, cols - 1);
        }

        for (int col = 0; col < cols; ++col) {
            dfs(dfs, 0, col);
            dfs(dfs, rows - 1, col);
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                } else if (board[row][col] == '#') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};