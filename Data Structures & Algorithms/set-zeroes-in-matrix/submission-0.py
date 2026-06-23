class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n, m = len(matrix), len(matrix[0])
        rows, columns = set(), set()

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    rows.add(i)
                    columns.add(j)
        
        for i in range(n):
            for j in range(m):
                if (i in rows) or (j in columns):
                    matrix[i][j] = 0

        