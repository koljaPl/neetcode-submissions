class Twitter {
private:
    int time = 0;

    unordered_map<int, vector<pair<int, int>>> tweetMap;

    unordered_map<int, unordered_set<int>> followMap;

    struct Tweet {
        int time;
        int tweetId;
        int followeeId;
        int index;

        bool operator<(const Tweet& other) const {
            return time < other.time;
        }
    };

public:
    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        followMap[userId].insert(userId);

        priority_queue<Tweet> maxHeap;

        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId) &&
                !tweetMap[followeeId].empty()) {

                int index = tweetMap[followeeId].size() - 1;

                auto [tweetTime, tweetId] =
                    tweetMap[followeeId][index];

                maxHeap.push({
                    tweetTime,
                    tweetId,
                    followeeId,
                    index - 1
                });
            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            Tweet curr = maxHeap.top();
            maxHeap.pop();

            res.push_back(curr.tweetId);

            if (curr.index >= 0) {
                auto [tweetTime, tweetId] =
                    tweetMap[curr.followeeId][curr.index];

                maxHeap.push({
                    tweetTime,
                    tweetId,
                    curr.followeeId,
                    curr.index - 1
                });
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};