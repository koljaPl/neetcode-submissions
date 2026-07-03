class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        int left = 0;
        int right = height.size() - 1;

        int leftMax = height[left]; 
        int rightMax = height[right];

        int res = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left += 1;
                leftMax = max(leftMax, height[left]);
                res += leftMax - height[left];
            } else {
                right -= 1;
                rightMax = max(rightMax, height[right]);
                res += rightMax - height[right];
            }
        }
        
        return res;
    }
};