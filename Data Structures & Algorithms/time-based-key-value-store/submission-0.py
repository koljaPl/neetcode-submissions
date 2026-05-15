from bisect import bisect_right

class TimeMap:

    def __init__(self):
        self.hash_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.hash_map:
            self.hash_map[key] = []
        self.hash_map[key].append([timestamp, value])

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.hash_map:
            return ""
        
        arr = self.hash_map[key]
        i = bisect_right(arr, [timestamp, chr(127)])
        if i == 0:
            return ""
        return arr[i-1][1]
        
