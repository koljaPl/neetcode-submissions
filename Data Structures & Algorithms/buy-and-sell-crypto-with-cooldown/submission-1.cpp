class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1)); 

        function<int(int, int)> dfs = [&](int i, int buying) {
            if (i >= n) return 0;

            if (dp[i][buying] != -1)
                return dp[i][buying];

            int cooldown = dfs(i + 1, buying);
            if (buying) {
                int buy = dfs(i + 1, 0) - prices[i];
                dp[i][buying] = max(buy, cooldown);
            } else {
                int sell = dfs(i + 2, 1) + prices[i];
                dp[i][buying] = max(sell, cooldown);
            }

            return dp[i][buying];
        };

        return dfs(0, 1);
    }
};