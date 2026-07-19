class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int max_profit = 0;

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int curr_profit = prices[right] - prices[left];
                max_profit = max(max_profit, curr_profit);
            } else {
                left = right;
            }
            right++;
        }

        return max_profit;
    }
};