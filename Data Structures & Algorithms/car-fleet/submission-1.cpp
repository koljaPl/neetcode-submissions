class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        cars.reserve(position.size());

        for (size_t i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        int fleets = 0;
        double curr_time = 0.0;
        
        for (const auto& [pos, spd] : cars) {
            double time_to_target = static_cast<double>(target - pos) / spd;

            if (time_to_target > curr_time) {
                fleets += 1;
                curr_time = time_to_target;
            }
        }
        
        return fleets;
    }
};