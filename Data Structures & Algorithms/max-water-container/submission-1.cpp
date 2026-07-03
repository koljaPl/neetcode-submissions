class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_area = 0;

        while (left < right) {
            int curr_area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, curr_area);
            
            if (height[left] < height[right])
                left += 1;
            else
                right -= 1;
        }

        return max_area;
    }
};