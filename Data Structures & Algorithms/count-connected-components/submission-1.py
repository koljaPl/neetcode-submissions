class DSU:
    def __init__(self, n):
        self.parents  = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x])

        return self.parents[x]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        if self.size[u] < self.size[v]:
            u, v = v, u

        self.parents[v] = u
        self.size[u] += self.size[v]

        return True

    def connected(self, a, b):
        return self.find(a) == self.find(b)

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        res = n

        for u, v in edges:
            if dsu.union(u, v):
                res -= 1
        
        return res