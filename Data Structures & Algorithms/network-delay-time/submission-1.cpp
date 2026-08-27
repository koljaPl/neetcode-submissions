class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        
        vector<bool> visited(n + 1, false);
        int t = 0;
        int visitedCount = 0;
        
        while (!minHeap.empty()) {
            auto [w1, n1] = minHeap.top();
            minHeap.pop();
            
            if (visited[n1]) continue;
            
            visited[n1] = true;
            visitedCount++;
            
            t = max(t, w1);
            
            for (const auto& edge : adj[n1]) {
                int n2 = edge.first;
                int w2 = edge.second;
                if (!visited[n2]) {
                    minHeap.push({w1 + w2, n2});
                }
            }
        }
        
        return visitedCount == n ? t : -1;
    }
};