class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        import collections

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)

        for i, eq in enumerate(equations):
            a, b = eq
            graph[a].append([b, values[i]])
            graph[b].append([a, 1 / values[i]])
        
        def bfs(src, target):
            if src not in graph or target not in graph:
                return -1

            q, visited = deque(), set()
            q.append([src, 1])
            visited.add(src)

            while q:
                n, w = q.popleft()

                if n == target:
                    return w
                
                for neighbor, weight in graph[n]:
                    if neighbor not in visited:
                        q.append([neighbor, w * weight])
                        visited.add(neighbor)
                
            return -1
        
        return [bfs(q[0], q[1]) for q in queries]
            