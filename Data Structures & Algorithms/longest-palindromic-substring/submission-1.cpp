class Solution {
private:
    string expand(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s) {
        string res;

        for (int i = 0; i < s.size(); i++) {
            string p1 = expand(s, i, i);
            string p2 = expand(s, i, i + 1);

            if (p1.size() > res.size())
                res = p1;
            
            if (p2.size() > res.size())
                res = p2;
        }

        return res;
    }
};