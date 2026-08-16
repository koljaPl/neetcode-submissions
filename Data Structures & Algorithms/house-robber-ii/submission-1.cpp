class Solution {
private:
    int rob_linear(const vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        
        for (int i = start; i <= end; ++i) {
            int temp = max(nums[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        
        return prev2;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        return max(
            rob_linear(nums, 0, nums.size() - 2),
            rob_linear(nums, 1, nums.size() - 1)
        );
    }
};