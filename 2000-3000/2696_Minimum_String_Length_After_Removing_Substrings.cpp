// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07
// Stack

class Solution {
public:
    int minLength(string s) {
        vector<char> st;

        for (char c : s) {
            if (!st.empty()) {
                if (c == 'B' && st.back() == 'A') st.pop_back();
                else if (c == 'D' && st.back() == 'C') st.pop_back();
                else st.push_back(c);
            }
            else st.push_back(c);
        }
        
        return st.size();
    }
};
