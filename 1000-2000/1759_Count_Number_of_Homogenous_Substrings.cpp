// https://leetcode.com/problems/count-number-of-homogenous-substrings/
// string + math

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;

    int countHomogenous(string s) {
        int n = s.size();
        ll strLen = 1, res = 0;

        char pre = s[0];

        for (int i = 1; i < n; i++) {
            if (s[i] == pre) strLen++;
            else {
                res += ((1 + strLen) * strLen / 2) % ub;
                res %= ub;

                strLen = 1;
            }

            pre = s[i];
        }

        res += ((1 + strLen) * strLen / 2) % ub;
        res %= ub;

        return res;
    }
};
