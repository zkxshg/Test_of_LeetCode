// https://leetcode.com/problems/crawler-log-folder/
// stack

class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<int> st;
        for (auto& s : logs) {
            if (s.substr(0, s.size() - 1) == ".") continue;
            else if (s.substr(0, s.size() - 1) == "..") {
                if (!st.empty()) st.pop_back();
            }
            else st.push_back(1);
        }
        
        return st.size();
    }
};
