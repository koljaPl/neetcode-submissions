from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.our_cache = {}
        self.priority = []

    def get(self, key: int) -> int:
        if key in self.our_cache:
            self.priority.remove(key)
            self.priority.append(key)
            return self.our_cache[key]
        
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.our_cache:
            self.our_cache[key] = value
            self.priority.remove(key)
            self.priority.append(key)
        else: 
            if len(self.our_cache) >= self.capacity:
                oldest_key = self.priority.pop(0)
                self.our_cache.pop(oldest_key)
            
            self.our_cache[key] = value
            self.priority.append(key)
        
