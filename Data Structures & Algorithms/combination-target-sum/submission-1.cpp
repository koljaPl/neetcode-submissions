class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
    
        auto backtracking = [&](auto& self, int i, int total) -> void {
            if (total == target) {
                res.push_back(curr);
                return;
            }

            if (i >= candidates.size() || total > target) {
                return;
            }
            
            curr.push_back(candidates[i]);
            self(self, i, total + candidates[i]);
            
            curr.pop_back();
            
            self(self, i + 1, total);
        };
        
        backtracking(backtracking, 0, 0);

        return res;
    }
};