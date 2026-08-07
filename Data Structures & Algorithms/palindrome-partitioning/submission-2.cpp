class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void backtracking(const string& s, int i, vector<string>& part, vector<vector<string>>& res) {
        int n = s.length();
        
        if (i == n) {
            res.push_back(part);
            return;
        }

        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                
                backtracking(s, j + 1, part, res);

                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        backtracking(s, 0, part, res);

        return res;
    }
};