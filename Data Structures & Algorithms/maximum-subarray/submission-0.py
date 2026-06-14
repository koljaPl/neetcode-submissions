class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]

        for i in range(len(nums)):
            curr = 0

            for j in range(i, len(nums)):
                curr += nums[j]
                res = max(res, curr)
        
        return res