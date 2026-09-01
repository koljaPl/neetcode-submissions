class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if (m == 0 || n == 0) {
            return max(m, n);
        }

        vector<vector<int>> cache(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j <= n; ++j) {
            cache[m][j] = n - j;
        }
        for (int i = 0; i <= m; ++i) {
            cache[i][n] = m - i;
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    cache[i][j] = cache[i + 1][j + 1];
                } else {
                    cache[i][j] = 1 + min({
                        cache[i + 1][j + 1],
                        cache[i][j + 1],
                        cache[i + 1][j]
                    });
                }
            }
        }

        return cache[0][0];
    }
};