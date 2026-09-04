/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    stack<int> s;
    stack<int> minStack;
public:
    MinStack() {    
    }
    
    void push(int value) {
        s.push(value);  
        if(minStack.empty() || minStack.top() >= value) {
            minStack.push(value);
        }
    }
    
    void pop() {
        if(!s.empty()) {
            if(s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

