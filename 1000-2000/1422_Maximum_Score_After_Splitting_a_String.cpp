// https://leetcode.com/problems/maximum-score-after-splitting-a-string/
// preSum

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        
        int OneNum = 0;
        for (char c : s) if (c == '1') OneNum++;

        int res = 0, num_0 = 0, num_1 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') num_0++;
            else num_1++;

            res = max(res, num_0 + OneNum - num_1);
        }

        return res;
    }
};
