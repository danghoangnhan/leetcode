/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Twitter {
public:
    Twitter() {
        this->counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        this->post[userId].push_back(make_pair(tweetId,this->counter));
        this->counter++;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto comp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> timeline(comp);
        
        for (const auto& tweet : post[userId]) {
            timeline.push(tweet);
        }
        
        for (int followeeId : follower[userId]) {
            for (const auto& tweet : post[followeeId]) {
                timeline.push(tweet);
            }
        }
        
        // Get the 10 most recent tweets
        for (int i = 0; i < 10 && !timeline.empty(); i++) {
            result.push_back(timeline.top().first);
            timeline.pop();
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        this->follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);

    }
    unordered_map<int,vector<pair<int,int>>> post;
    unordered_map<int, unordered_set<int>> follower;
    int counter;
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

