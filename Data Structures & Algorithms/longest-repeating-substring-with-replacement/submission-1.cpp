class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> count;
        int left = 0;
        int max_count = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            max_count = max(max_count, count[s[right]]);

            while ((right - left + 1) - max_count > k) {
                count[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
