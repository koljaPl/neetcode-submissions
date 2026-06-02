class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        used = [False] * n

        def backtracking(curr):
            if len(curr) == n:
                res.append(curr[:])
                return
            
            for i in range(n):
                if used[i]:
                    continue

                used[i] = True
                curr.append(nums[i])

                backtracking(curr)

                curr.pop()
                used[i] = False
        
        backtracking([])

        return res