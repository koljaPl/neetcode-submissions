class DSU:
    def __init__(self, n):
        self.comps = n
        self.parents  = list(range(n + 1))
        self.size = [1] * (n + 1)

    def find(self, x):
        if self.parents[x] != x:
            self.parents[x] = self.find(self.parents[x]) # Path Compression

        return self.parents[x]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)

        if u == v:
            return False

        self.comps -= 1
        if self.size[u] < self.size[v]:
            u, v = v, u

        self.parents[v] = u
        self.size[u] += self.size[v]

        return True

    def connected(self, a, b):
        return self.find(a) == self.find(b)
    
    def components(self):
        return self.comps

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > n - 1:
            return False
        
        dsu = DSU(n)

        for u, v in edges:
            if not dsu.union(u, v):
                return False
            
        return dsu.components() == 1