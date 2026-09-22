class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;

        for (const string& word : words) {
            for (char c : word) {
                adj[c];
            }
        }

        for (int i = 0; i + 1 < words.size(); ++i) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int minLen = min(w1.size(), w2.size());

            if (w1.size() > w2.size() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        unordered_map<char, int> visited;
        string res;

        function<bool(char)> dfs = [&](char c) -> bool {
            if (visited[c] == 1)
                return true;

            if (visited[c] == 2)
                return false;

            visited[c] = 1;

            for (char next : adj[c]) {
                if (dfs(next))
                    return true;
            }

            visited[c] = 2;
            res += c;

            return false;
        };

        for (auto& [c, neighbors] : adj) {
            if (dfs(c))
                return "";
        }

        reverse(res.begin(), res.end());

        return res;
    }
};