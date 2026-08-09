class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> heap;

        for (auto& point : points) {
            int x = point[0];
            int y = point[1];

            int dist = x * x + y * y;

            heap.push({dist, x, y});

            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<vector<int>> res;

        while (!heap.empty()) {
            int x = heap.top()[1];
            int y = heap.top()[2];

            res.push_back({x, y});
            heap.pop();
        }

        return res;
    }
};