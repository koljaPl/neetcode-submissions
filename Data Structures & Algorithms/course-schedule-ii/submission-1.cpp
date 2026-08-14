class Solution {
public:
    vector<vector<int>> prereq;
    unordered_set<int> visited;
    unordered_set<int> cycle;
    vector<int> res;

    bool dfs(int crs) {
        if (cycle.count(crs))
            return false;

        if (visited.count(crs))
            return true;

        cycle.insert(crs);

        for (int pre : prereq[crs]) {
            if (!dfs(pre))
                return false;
        }

        cycle.erase(crs);
        visited.insert(crs);
        res.push_back(crs);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        prereq.resize(numCourses);

        for (auto& p : prerequisites) {
            int crs = p[0];
            int pre = p[1];
            prereq[crs].push_back(pre);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return {};
        }

        return res;
    }
};