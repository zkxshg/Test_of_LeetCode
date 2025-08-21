// stack: O(n)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(); if (n < 3) return true;
        
        int pu = 0, po = 0;
        stack <int> st;
        
        for (int i = 0; i < n; i++) {
            st.push(pushed[pu]); pu++;
            
            while (!st.empty() && st.top() == popped[po]) {
                st.pop(); po++;
            }
        } 
      
        return st.empty();
    }
};
