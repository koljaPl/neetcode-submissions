import copy

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def backtracking(last: list, start_index: int):
            ans.append(copy.copy(last))

            for i in range(start_index, len(nums)):
                last.append(nums[i])
                backtracking(last, i + 1)
                last.pop()
            
        last = []
        backtracking(last, 0)

        return ans