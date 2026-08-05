class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        function<void(int, int)> backtrack = [&](int index, int total) {
            if (total == target) {
                result.push_back(current);
                return;
            }

            for (int i = index; i < candidates.size(); ++i) {
                if (i > index && candidates[i] == candidates[i - 1]) {
                    continue;
                }

                if (total + candidates[i] > target) {
                    break;
                }

                current.push_back(candidates[i]);

                backtrack(i + 1, total + candidates[i]);

                current.pop_back();
            }
        };

        backtrack(0, 0);

        return result;
    }
};
