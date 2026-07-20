class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char ch : s1)
            need[ch - 'a']++;

        for (int i = 0; i < n; i++)
            window[s2[i] - 'a']++;

        if (window == need)
            return true;

        for (int right = n; right < m; right++) {
            window[s2[right] - 'a']++;

            int left = right - n;
            window[s2[left] - 'a']--;

            if (window == need)
                return true;
        }

        return false;
    }
};