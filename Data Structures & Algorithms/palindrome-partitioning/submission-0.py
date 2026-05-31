class Solution:
    def isPalindrome(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False

            l, r = l + 1, r - 1

        return True
        

    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        res = []
        part = []

        def backtracking(i):
            if i == n:
                res.append(part.copy())
                return

            for j in range(i, n):
                if self.isPalindrome(s, i, j):
                    part.append(s[i : j + 1])
                    backtracking(j + 1)
                    part.pop()
        
        backtracking(0)

        return res    
        