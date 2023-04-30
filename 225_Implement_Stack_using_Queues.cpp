// https://leetcode.com/problems/implement-stack-using-queues/
// queue + stack

class MyStack {
public:
    queue<int> q0;
    queue<int> q1;
    
    int exchange(queue<int>& q0, queue<int>& q1) {
        int res = 0;
        while (q1.size() > 1) {
            q0.push(q1.front()); q1.pop();
        }
        if (q1.size() == 1) {
            res = q1.front(); q1.pop();
        }
        return res;
    }
    
    void clear(queue<int> &q) {
        queue<int> empty;
        swap(q, empty);
    }
    
    MyStack() {
        clear(q0); clear(q1);
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int res = exchange(q0, q1);
        if (!q0.empty()) {
            int bk = exchange(q1, q0);
            if (bk) q1.push(bk);
        }
        return res;
    }
    
    int top() {
        int res = exchange(q0, q1);
        q0.push(res);
        if (!q0.empty()) {
            int bk = exchange(q1, q0);
            if (bk) q1.push(bk);
        }
        return res;
    }
    
    bool empty() {
        return q1.empty();
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
