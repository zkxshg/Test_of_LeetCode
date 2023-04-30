// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
// string

class Solution {
public:
    bool areNumbersAscending(string s) {
        int last = -1, tem = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') tem = tem * 10 + (c - '0');
            else if (tem) {
                if (tem <= last) return false;
                else {
                    last = tem; tem = 0;
                }
            }
        }
        if (tem && tem <= last) return false;
        return true;
    }
};
