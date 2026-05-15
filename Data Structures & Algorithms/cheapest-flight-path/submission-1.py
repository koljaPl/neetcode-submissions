class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        cities = collections.defaultdict(list)

        for u, v, w in flights:
            cities[u].append((v, w))
        
        minHeap = [(0, src, 0)]
        visited = {}

        while minHeap:
            w1, n1, stops_used = heapq.heappop(minHeap)

            if n1 in visited and visited[n1] <= stops_used:
                continue
            
            visited[n1] = stops_used

            if n1 == dst:
                return w1

            if stops_used <= k:
                for n2, w2 in cities[n1]:
                    heapq.heappush(minHeap, (w1 + w2, n2, stops_used + 1))
            
        return -1
