class CountSquares {
private:
    unordered_map<int, unordered_map<int, int>> cnt;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        cnt[x][y]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];

        int res = 0;

        for (auto &[x, col] : cnt) {
            if (x == px) continue;

            int d = x - px;

            int y1 = py + d;
            int y2 = py - d;

            if (cnt[x].count(y1)) {
                res += cnt[x][y1] * cnt[px][y1] * cnt[x][py];
            }

            if (cnt[x].count(y2)) {
                res += cnt[x][y2] * cnt[px][y2] * cnt[x][py];
            }
        }

        return res;
    }
};
