class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res, curr = nums[0], 0

        for num in nums:
            if curr < 0:
                curr = 0
            
            curr += num
            res = max(res, curr)
        
        return res