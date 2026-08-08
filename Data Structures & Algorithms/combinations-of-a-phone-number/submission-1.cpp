class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> letters = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> res;

        function<void(int, string)> backtracking =
            [&](int index, string path) {
                if (index == digits.size()) {
                    res.push_back(path);
                    return;
                }

                int digit = digits[index] - '0';

                for (char letter : letters[digit]) {
                    backtracking(index + 1, path + letter);
                }
            };

        backtracking(0, "");

        return res;
    }
};