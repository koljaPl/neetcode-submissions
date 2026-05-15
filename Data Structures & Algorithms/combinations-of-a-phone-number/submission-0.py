class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        dict_by_num = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"],
        }

        res = []

        def backtracking(index, path):
            if index == len(digits):
                res.append(path)
                return
            
            for letter in dict_by_num[digits[index]]:
                backtracking(index + 1, path + letter)

        backtracking(0, "")
        return res