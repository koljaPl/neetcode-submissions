class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars_set;
        int res = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            while (chars_set.contains(s[right])) {
                chars_set.erase(s[left]);
                left++;
            }
            chars_set.insert(s[right]);

            res = max(res, right - left + 1);
        }

        return res;
    }
};