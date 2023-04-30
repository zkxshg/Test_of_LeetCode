class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> MS;
    vector<int> minv;
    
    MinStack() {}
    
    void push(int x) {
        MS.push_back(x);
        if (minv.empty() || minv.back() >= x) minv.push_back(x);
        
    }
    
    void pop() {
        if (minv.back() == MS.back()) minv.pop_back();
        MS.pop_back();
    }
    
    int top() {
        if(!MS.empty()) return MS.back();
        return -1;
    }
    
    int getMin() {
        if (!minv.empty()) return minv.back();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
