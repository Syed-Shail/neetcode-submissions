class Twitter {
public:
    unordered_map<int,set<int>> list;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});  
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>>q;
        for(auto& p : tweets[userId]){
            q.push(p);
        }
        for(auto& id: list[userId]){
             for(auto& p : tweets[id]){
            q.push(p);
        }
        } 
    
    int cnt =0;
    while(!q.empty()&& cnt!=10){
        res.push_back(q.top().second);
        q.pop();
        cnt++;
    }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            list[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            list[followerId].erase(followeeId);
        }
    }
};
