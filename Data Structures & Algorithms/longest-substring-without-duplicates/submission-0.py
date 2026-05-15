class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars_set = set()
        result = 0
        l = 0

        for r in range(len(s)):
            while s[r] in chars_set:
                chars_set.remove(s[l])
                l += 1
            chars_set.add(s[r])
            result = max(result, r - l + 1)
        
        return result