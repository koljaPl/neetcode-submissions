class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<int>> dp(
            s1.size() + 1,
            vector<int>(s2.size() + 1, -1)
        );

        function<bool(int, int)> dfs = [&](int i, int j) -> bool {
            if (i == s1.size() && j == s2.size())
                return true;

            if (dp[i][j] != -1)
                return dp[i][j];

            bool res = false;

            if (i < s1.size() &&
                s1[i] == s3[i + j] &&
                dfs(i + 1, j))
            {
                res = true;
            }

            if (!res &&
                j < s2.size() &&
                s2[j] == s3[i + j] &&
                dfs(i, j + 1))
            {
                res = true;
            }

            dp[i][j] = res;
            return res;
        };

        return dfs(0, 0);
    }
};