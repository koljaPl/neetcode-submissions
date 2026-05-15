import copy

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []

        def backtracking(last: list, start_index: int):
            ans.append(copy.copy(last))

            for i in range(start_index, len(nums)):
                if i > start_index and nums[i] == nums[i-1]:
                    continue
                last.append(nums[i])
                backtracking(last, i + 1)
                last.pop()
            
        last = []
        backtracking(last, 0)

        return ans