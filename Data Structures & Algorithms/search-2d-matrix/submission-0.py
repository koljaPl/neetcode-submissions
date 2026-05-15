class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def binar_search(nums: list) -> bool:
            left, right = 0, len(nums) - 1

            while left <= right:
                mid = (left + right)// 2

                if nums[mid] == target:
                    return True
                elif nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
        
            return False
            

        for row in matrix:
            if binar_search(row):
                return True
            
        return False