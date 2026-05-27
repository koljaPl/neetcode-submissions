class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        prereq = { c:[] for c in range(numCourses) }
        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        res = []
        visited = set()
        cycle = set()

        def dfs(crs):
            if crs in cycle:
                return False
            if crs in visited:
                return True
            
            cycle.add(crs)
            
            for pre in prereq[crs]:
                if not dfs(pre):
                    return False
            
            cycle.remove(crs)
            visited.add(crs)
            res.append(crs)
            
            return True
        
        for i in range(numCourses):
            if dfs(i) == False:
                return []
            
        return res