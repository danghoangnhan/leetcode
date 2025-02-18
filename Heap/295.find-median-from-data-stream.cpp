/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        this->minHeap.emplace(num);
        this->maxHeap.emplace(num);
    }
    
    double findMedian() {
        return double(this->maxHeap.top()+this->minHeap.top())/2.0
    }
    priority_queue<int,vector<int>,greater<int>> maxHeap;     
    priority_queue<int,vector<int>,less<int>> minHeap;   
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

