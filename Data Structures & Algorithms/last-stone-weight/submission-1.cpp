class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());

            int y = stones.back();
            stones.pop_back();

            int x = stones.back();
            stones.pop_back();

            if (x != y)
                stones.push_back(y - x);
        }
        
        if (!stones.empty())
            return stones[0];
        else
            return 0;
    }
};