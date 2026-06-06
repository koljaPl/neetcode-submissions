class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Time: O(n) ; Mem: O(1)
        res = max(nums)
        curr_min, curr_max = 1, 1

        for n in nums:
            temp_max = curr_max

            curr_max = max(n * curr_max, n * curr_min, n)
            curr_min = min(n * temp_max, n * curr_min, n)
            
            res = max(res, curr_max)
        
        return res
