class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> cnt;

        for (int x : hand)
            cnt[x]++;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &[card, _] : cnt)
            pq.push(card);

        while (!pq.empty()) {
            int start = pq.top();

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                if (cnt[card] == 0)
                    return false;

                cnt[card]--;

                if (cnt[card] == 0) {
                    if (pq.empty() || pq.top() != card)
                        return false;
                    pq.pop();
                }
            }
        }

        return true;
    }
};