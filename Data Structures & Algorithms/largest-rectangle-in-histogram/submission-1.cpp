class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int left;
                if (!st.empty())
                    left = st.top();
                else
                    left = -1;
                
                int width = i - left - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        return max_area;
    }
};