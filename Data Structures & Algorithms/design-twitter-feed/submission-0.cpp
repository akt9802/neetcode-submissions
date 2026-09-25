class Twitter {
public:
    // data structure to store tweets 
    // (userId,{time,tweetId})
    unordered_map<int,vector<pair<int,int>>> tweets;

    // data structure to store following/followers
    // {userID,(set of userId who are friend of this user)}
    unordered_map<int,unordered_set<int>> following;

    // time 
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // recent time on top(5 3 2 etc...)
        // pq -> time,tweetId
        priority_queue<pair<int,int>> pq;

        // extract his own tweets 
        for(auto tweet:tweets[userId]){
            pq.push(tweet);
        }

        // tweets of followers of users
        for(auto followee:following[userId]){
            for(auto tweet:tweets[followee]){
                pq.push(tweet);
            }
        }

        vector<int> result;
        while(!pq.empty() && result.size()<10){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
