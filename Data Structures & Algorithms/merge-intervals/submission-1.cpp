class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0]; 
        });
        vector<vector<int>> merged;

        int curr_start = intervals[0][0];
        int curr_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start <= curr_end) {
                curr_end = max(curr_end, end);
            } else {
                merged.push_back({curr_start, curr_end});
                curr_start = start;
                curr_end = end;
            }
        }

        merged.push_back({curr_start, curr_end});
        return merged;
    }
};