class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> hm;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = hm.find(key);

        if (it == hm.end()) {
            return "";
        }

        const vector<pair<int, string>>& arr = it->second;

        auto pos = upper_bound(
            arr.begin(),
            arr.end(),
            timestamp,
            [](int target, const pair<int, string>& element) {
                return target < element.first;
            }
        );

        if (pos == arr.begin())
            return "";

        pos--;
        return pos -> second;
    }
};