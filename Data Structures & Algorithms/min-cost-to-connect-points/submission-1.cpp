class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int distance = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({distance, j});
                adj[j].push_back({distance, i});
            }
        }

        int result = 0;

        vector<bool> visited(n, false);
        int visitedCount = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minHeap;

        minHeap.push({0, 0});

        while (visitedCount < n) {
            auto [cost, vertex] = minHeap.top();
            minHeap.pop();

            if (visited[vertex]) {
                continue;
            }

            visited[vertex] = true;
            visitedCount++;
            result += cost;

            for (auto [neighborCost, neighbor] : adj[vertex]) {
                if (!visited[neighbor]) {
                    minHeap.push({neighborCost, neighbor});
                }
            }
        }

        return result;
    }
};