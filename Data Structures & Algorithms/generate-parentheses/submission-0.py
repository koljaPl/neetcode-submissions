class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def backtracking(opened, closed, curr):
            if len(curr) == 2 * n:
                ans.append(curr)
                return

            if opened < n:
                backtracking(opened + 1, closed, curr + "(")

            if closed < opened:
                backtracking(opened, closed + 1, curr + ")")

        backtracking(0, 0, "")        
        return ans