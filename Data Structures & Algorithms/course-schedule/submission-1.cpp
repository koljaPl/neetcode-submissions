class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (int i = 0; i < numCourses; ++i) {
            preMap[i] = vector<int>();
        }

        for (const auto& pair : prerequisites) {
            int crs = pair[0];
            int pre = pair[1];
            preMap[crs].push_back(pre);
        }

        unordered_set<int> visited;

        function<bool(int)> dfs = [&](int crs) {
            if (visited.count(crs)) return false;
            if (preMap[crs].empty()) return true;

            visited.insert(crs);
            for (int pre : preMap[crs]) {
                if (!dfs(pre)) return false;
            }

            visited.erase(crs);
            preMap[crs].clear();

            return true;
        };
            
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }
            
        return true;
    }
};