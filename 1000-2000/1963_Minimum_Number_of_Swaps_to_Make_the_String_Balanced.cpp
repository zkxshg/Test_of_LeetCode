// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/?envType=daily-question&envId=2024-10-08
// Stack

class Solution {
public:
    int minSwaps(string s) {
        vector<char> st;
        for (char c : s) {
            if (!st.empty() && c == ']' && st.back() == '[') st.pop_back();
            else st.push_back(c);
        }
        return st.size() / 4 + ((st.size() % 4 > 0) ? 1 : 0);
    }
};
