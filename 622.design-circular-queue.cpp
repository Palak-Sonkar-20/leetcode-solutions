/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
    queue<int> q;
    int k;
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        // Add the value to the queue
        q.push(value);

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        q.pop();
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q.front();       
        
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
        
    }
    
    bool isFull() {
        if(q.size() == k) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

