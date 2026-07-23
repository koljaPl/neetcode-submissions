/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        if (n == 0) {
            return 0;
        }

        vector<int> starts;
        vector<int> ends;

        starts.reserve(n);
        ends.reserve(n);

        for (const Interval& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int left = 0;
        int right = 0;

        int count = 0;
        int res = 0;

        while (left < n) {
            if (starts[left] < ends[right]) {
                count++;
                left++;
            } else {
                count--;
                right++;
            }

            res = max(res, count);
        }

        return res;
    }
};
