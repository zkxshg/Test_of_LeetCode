// https://leetcode.com/problems/orderly-queue/
// string + sort

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = s;
        if (k == 1) {
            for (int i = 0; i < s.size(); i++) {
                string temp = s.substr(i) + s.substr(0, i);
                if (temp < res) res = temp;
            }
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }
        return res;
    }
};
