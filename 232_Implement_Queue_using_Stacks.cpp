// https://leetcode.com/problems/implement-queue-using-stacks/
// stack + queue

class MyQueue {
public:
    vector<int> st0;
    vector<int> st1;
    
    MyQueue() {
        st0.clear(); st1.clear();
    }
    
    void exchange(vector<int>& st0, vector<int>& st1) {
        while (!st1.empty()) {
            st0.push_back(st1.back()); 
            st1.pop_back();
        }
    }
    
    void push(int x) {
        if (st1.empty()) st1.push_back(x);
        else {
            exchange(st0, st1);
            st0.push_back(x);
            exchange(st1, st0);
        }
    }
    
    int pop() {
        int res = 0;
        if (!st1.empty()) {
            res = st1.back(); st1.pop_back();
        }
        return res;
    }
    
    int peek() {
        return st1.back();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
