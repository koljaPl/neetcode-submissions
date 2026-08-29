class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> cities(n);

        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            cities[u].push_back({v, w});
        }

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        minHeap.push({0, src, 0});

        vector<int> visited(n, INT_MAX);

        while (!minHeap.empty()) {
            auto [cost, city, stops_used] = minHeap.top();
            minHeap.pop();

            if (visited[city] <= stops_used) {
                continue;
            }

            visited[city] = stops_used;

            if (city == dst) {
                return cost;
            }

            if (stops_used <= k) {
                for (auto [next_city, price] : cities[city]) {
                    minHeap.push({
                        cost + price,
                        next_city,
                        stops_used + 1
                    });
                }
            }
        }

        return -1;
    }
};