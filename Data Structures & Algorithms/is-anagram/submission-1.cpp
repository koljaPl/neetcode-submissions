class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int charCounts[256] = {0};

        for (size_t i = 0; i < s.length(); ++i) {
            charCounts[static_cast<unsigned char>(s[i])]++;
            charCounts[static_cast<unsigned char>(t[i])]--;
        }

        for (int count : charCounts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};