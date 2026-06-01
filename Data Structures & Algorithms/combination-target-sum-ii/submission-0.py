class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def backtracking(idx, curr, total):
            if total == target:
                res.append(curr.copy())
                return

            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i - 1]:
                    continue
                if total + candidates[i] > target:
                    break

                curr.append(candidates[i])
                backtracking(i + 1, curr, total + candidates[i])
                curr.pop()
        
        backtracking(0, [], 0)

        return res