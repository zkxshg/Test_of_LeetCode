// https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30
// Stack

class CustomStack {
public:
    int ms;
    vector<int> st;

    CustomStack(int maxSize) {
        st.clear();
        ms = maxSize;
    }
    
    void push(int x) {
        if (st.size() < ms) st.push_back(x);
        
    }
    
    int pop() {
        if (st.empty()) return -1;

        int tp = st.back();
        st.pop_back();
        return tp;
    }
    
    void increment(int k, int val) {
        vector<int> tmST;

        while (st.size() > k) {
            tmST.push_back(st.back());
            st.pop_back();
        }

        while (!st.empty()) {
            tmST.push_back(st.back() + val);
            st.pop_back();
        }

        while (!tmST.empty()) {
            st.push_back(tmST.back());
            tmST.pop_back();
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
