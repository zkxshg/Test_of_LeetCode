https://leetcode.com/problems/baseball-game/
// stack

class Solution {
public:
    int str2int(string s) {
        int res = 0;
        for (char c : s) res = res * 10 + (c - '0');
        return res;
    }
    
    int calPoints(vector<string>& ops) {
        vector<int> st;
        
        for (auto& s : ops) {
            if (s[0] >= '0' && s[0] <= '9') st.push_back(str2int(s));
            else if (s[0] == '+') st.push_back(st[st.size() - 1] + st[st.size() - 2]);
            else if (s[0] == 'D') st.push_back(st.back() * 2);
            else if (s[0] == 'C') st.pop_back();
            else if (s[0] == '-') st.push_back(-1 * str2int(s.substr(1)));
        }
        
        return accumulate(st.begin(), st.end(), 0);
    }
};
