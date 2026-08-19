class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        
        if (total % 2 != 0)
            return false;

        long long target = total / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j > num - 1; j--)
                dp[j] = dp[j] || dp[j - num];
        }

        return dp[target];
    }
};