class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def hours_needed(k: int) -> int:
            hours = 0

            for pile in piles:
                hours += (pile + k - 1) // k
            
            return hours
                
        
        left, right = 1, max(piles)
        result = right

        while left <= right:
            mid = (left + right) // 2

            if hours_needed(mid) <= h:
                result = mid
                right = mid - 1
            else:
                left = mid + 1

        return result