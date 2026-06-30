typedef tuple<int, int, int> tp;
class Twitter {
private:
    // User ID mapped to set all its followees
    unordered_map<int, unordered_set<int>> followMap;

    // User ID mapped to all pairs of (time, tweetID)
    unordered_map<int, vector<pair<int, int>>> tweetMap;

    int count;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
       tweetMap[userId].push_back({count++, tweetId}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        // 1st - time, 2nd - userId, 3rd - tweet index
        priority_queue<tp> tweetHeap;
        // Adding the users latest tweet in the heap
        if(tweetMap.count(userId) && !tweetMap[userId].empty()) {
            int latestTweetIdx = tweetMap[userId].size() - 1;
            int time = tweetMap[userId][latestTweetIdx].first;

            tweetHeap.push({time, userId, latestTweetIdx});
        }

        // Adding the followees latest tweets
        if(followMap.count(userId)) {
            for(int followeeId : followMap[userId]) {
                if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                    int latestTweetIdx = tweetMap[followeeId].size() - 1;
                    int time = tweetMap[followeeId][latestTweetIdx].first;

                    tweetHeap.push({time, followeeId, latestTweetIdx});
                }
            }
        }

        // Add latest tweets to the result array based on what's in the heap and
        // push the next latest tweet of the user just popped. Though this increases
        // time complexity, in case of many followers and many tweets, we don't have
        // to have a large heap size
        while(res.size() < 10 && !tweetHeap.empty()) {
            tp latest = tweetHeap.top();
            int uid = get<1>(latest);
            int tweetIdx = get<2>(latest);
            tweetHeap.pop();
            int tweetId = tweetMap[uid][tweetIdx].second;
            res.push_back(tweetId);

            if (tweetIdx > 0) {
                int prevIdx = tweetIdx - 1;
                int time = tweetMap[uid][prevIdx].first;
                tweetHeap.push({time, uid, prevIdx});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        if (!followMap.count(followerId)) {
            unordered_set<int> followees;
            followees.insert(followeeId);
            followMap[followerId] = followees;
            return;
        } 

        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (!followMap.count(followerId)) {
            return;
        }
        followMap[followerId].erase(followeeId);
    }
};
