class Solution {
private:
    void backtracking(
        const vector<int>& nums,
        int startIndex,
        vector<int>& current,
        vector<vector<int>>& res
    ) {
        res.push_back(current);

        for (int i = startIndex; i < nums.size(); ++i) {
            current.push_back(nums[i]);

            backtracking(
                nums,
                i + 1,
                current,
                res
            );

            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;

        backtracking(nums, 0, current, res);

        return res;
    }
};
