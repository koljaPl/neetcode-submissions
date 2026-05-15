"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        start = sorted([interval.start for interval in intervals])
        end = sorted([interval.end for interval in intervals])
        
        res, count = 0, 0
        left, right = 0, 0

        while left < len(intervals):
            if start[left] < end[right]:
                left += 1
                count += 1
            else:
                right += 1
                count -= 1

            res = max(res, count)
            
        return res
