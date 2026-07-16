class Solution {
private:
    long long hours_needed(int k, const vector<int>& piles) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1LL) / k;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (hours_needed(mid, piles) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};