class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        def rob_linear(houses):
            prev1, prev2 = 0, 0

            for hous in houses:
                temp = max(hous + prev1, prev2)
                prev1 = prev2
                prev2 = temp

            return prev2
        
        return max(
            rob_linear(nums[:-1]),
            rob_linear(nums[1:])
        )

