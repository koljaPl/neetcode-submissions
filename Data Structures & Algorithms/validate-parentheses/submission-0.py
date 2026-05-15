class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch in ['(', '{', '[']:
                stack.append(ch)
            else:
                if not stack:
                    return False
                else:
                    x = stack.pop() + ch

                    if x not in ["()", "{}", "[]"]:
                        return False
        
        return not stack