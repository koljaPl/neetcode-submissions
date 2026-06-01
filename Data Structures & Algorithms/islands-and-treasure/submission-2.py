class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS, COLS = len(grid), len(grid[0])
        visited = set()
        q = deque()

        def addGrid(r, c):
            if (r < 0 or r == ROWS or c < 0 or c == COLS or
                (r, c) in visited or grid[r][c] == -1):
                return
            
            visited.add((r, c))
            q.append([r, c])

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    q.append([r, c])
                    visited.add((r, c))
        
        dist = 0
        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                grid[r][c] = dist

                addGrid(r + 1, c)
                addGrid(r - 1, c)
                addGrid(r, c + 1)
                addGrid(r, c - 1)
            
            dist += 1