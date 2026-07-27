class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = deque()
        res = []

        for right, value in enumerate(nums):
            while queue and nums[queue[-1]] <= value:
                queue.pop()

            queue.append(right)

            left = right - k + 1

            if queue[0] < left:
                queue.popleft()

            if left >= 0:
                res.append(nums[queue[0]])

        return res