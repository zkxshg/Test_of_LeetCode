// https://leetcode.com/problems/separate-black-and-white-balls/?envType=daily-question&envId=2024-10-15
// Two Points

class Solution {
public:
    #define ll long long
    long long minimumSteps(string s) {
        int n = s.size();

        vector<int> blackPos;
        int pos = 0;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (pos < blackPos.size()) {
                    res += (i - blackPos[pos]);
                    pos++;
                    blackPos.push_back(i);
                }

            }
            else blackPos.push_back(i);
        }

        return res;
    }
};
