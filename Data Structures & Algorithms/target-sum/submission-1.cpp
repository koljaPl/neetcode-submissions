class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^
                   (hash<int>()(p.second) << 1);
        }
    };

    unordered_map<pair<int, int>, int, PairHash> dp;

    int dfs(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }

        pair<int, int> state = {i, total};

        if (dp.count(state))
            return dp[state];

        dp[state] =
            dfs(i + 1, total + nums[i], nums, target) +
            dfs(i + 1, total - nums[i], nums, target);

        return dp[state];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }
};