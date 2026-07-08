class Twitter {
private: 
    int global_tweet_count = 0;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {
        global_tweet_count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].emplace_back(global_tweet_count++, tweetId);

        if (tweetMap[userId].size() > 10)
            tweetMap[userId].erase(tweetMap[userId].begin());
    }
    
    vector<int> getNewsFeed(int userId) {
            vector<int> result;
    followMap[userId].insert(userId);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> headHeap;

    for (int followee : followMap[userId]) {
        if (!tweetMap.count(followee)) continue;

        int idx = tweetMap[followee].size() - 1;
        auto &p = tweetMap[followee][idx];

        headHeap.push({p.first, followee, idx});
        if (headHeap.size() > 10)
            headHeap.pop();
    }

    priority_queue<vector<int>> pq;

    while (!headHeap.empty()) {
        auto t = headHeap.top();
        headHeap.pop();

        int followee = t[1];
        int idx = t[2];

        auto &p = tweetMap[followee][idx];
        pq.push({p.first, p.second, followee, idx - 1});
    }

    while (!pq.empty() && result.size() < 10) {
        auto t = pq.top();
        pq.pop();

        result.push_back(t[1]);

        int followee = t[2];
        int idx = t[3];

        if (idx >= 0) {
            auto &p = tweetMap[followee][idx];
            pq.push({p.first, p.second, followee, idx - 1});
        }
    }

    return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followMap[followerId].count(followeeId))
            followMap[followerId].erase(followeeId);
    }
};
