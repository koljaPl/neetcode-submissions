class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);

        int index = distance(nums.begin(), it);

        if (index < nums.size() && nums[index] == target)
            return index;
        else
            return -1;
    }
};