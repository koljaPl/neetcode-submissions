class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        int curr_min = 1;
        int curr_max = 1;

        for (int n : nums) {
            int temp_max = curr_max;

            curr_max = max({n * curr_max, n * curr_min, n});
            curr_min = min({n * temp_max, n * curr_min, n});
            
            res = max(res, curr_max);
        }
        
        return res;
    }
};