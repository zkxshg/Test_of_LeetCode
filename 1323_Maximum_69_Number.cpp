// https://leetcode.com/problems/maximum-69-number/
// stack

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> st;
        while (num) {
            st.push_back(num % 10); num /= 10;
        }
        int res = 0, change = 1;
        while (!st.empty()) {
            res *= 10;
            if (st.back() == 6 && change) {
                 res += 9; change = 0;
            }
            else res += st.back();
            st.pop_back();
        }
        return res;
    }
};
