DIRECTIONS = ((1, 0), (-1, 0), (0, 1), (0, -1))

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        n, m = len(grid), len(grid[0])
        visited = set()
        is_island = 0

        def bfs(row, col):
            q = collections.deque()

            visited.add((row, col))
            q.append((row, col))

            while q:
                row, col = q.popleft()

                for dir_row, dir_col in DIRECTIONS:
                    curr_row = row + dir_row
                    curr_col = col + dir_col

                    if (0 <= curr_row < n and
                        0 <= curr_col < m and
                        grid[curr_row][curr_col] == "1" and
                        (curr_row, curr_col) not in visited):

                        q.append((curr_row, curr_col))
                        visited.add((curr_row, curr_col))

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1" and ((i, j) not in visited):
                    bfs(i, j)
                    is_island += 1

        return is_island