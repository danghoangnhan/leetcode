#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        this->data = new vector<int>;
    }
    
    void push(int x) {
        this->data->push_back(x);
    }
    
    int pop() {
        int value = this->data->front();
        this->data->erase(data->begin());
        return value;
    }
    
    int peek() {
        int value = this->data->front();
        return value;
    }
    
    bool empty() {
        return this->data->empty();
    }
private:
    vector<int> *data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

