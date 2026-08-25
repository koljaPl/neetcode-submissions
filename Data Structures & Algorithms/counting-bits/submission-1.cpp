class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        int sub = 1;

        for (int i = 1; i < n + 1; i++) {
            if (sub * 2 == i) {
                sub = i;
            }
            
            res[i] = res[i - sub] + 1;
        }

        return res;
    }
};