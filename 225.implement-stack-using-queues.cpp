/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
    queue<int> q;
    queue<int> temp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
    }
    
    int pop() {
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        int topElement = q.front();
        q.pop();
        swap(q, temp);
        return topElement;
    }
    
    int top() {
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        int topElement = q.front();
        temp.push(topElement);
        q.pop();
        swap(q, temp);
        return topElement;
        
    }
    
    bool empty() {
        return q.empty() && temp.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

