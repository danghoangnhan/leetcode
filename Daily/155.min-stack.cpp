/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        stack.push(val);
        // If min_stack is empty or val is the new minimum, push it onto min_stack
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        // If the element being popped is the minimum, pop it from min_stack too
        if (stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        stack.pop();
    }
    
    int top() {
        if (stack.empty()) return INT_MIN; // Return an appropriate value if stack is empty
        return stack.top();
    }
    
    int getMin() {
        if (min_stack.empty()) return INT_MIN; // Return an appropriate value if min_stack is empty
        return min_stack.top();
    }

private:
    stack<int> stack, min_stack;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

