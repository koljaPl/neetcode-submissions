class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int money : nums) {
            int temp = max(money + prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }

        return prev2;
    }
};