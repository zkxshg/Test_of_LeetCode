// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2024-07-30
// DP

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp_a(n);
        vector<int> dp_b(n);

        int cou = 0; if (s[0] == 'b') cou++;
        for (int i = 1; i < n; i++) {
            if (s[i] == 'a') {
                dp_a[i] = dp_a[i - 1] + cou;
                cou = 0;
            }
            else {
                dp_a[i] = dp_a[i - 1];
                cou++;
            }
        }

        cou = 0; if (s[n - 1] == 'a') cou++;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == 'b') {
                dp_b[i] = dp_b[i + 1] + cou;
                cou = 0;
            }
            else {
                dp_b[i] = dp_b[i + 1];
                cou++;
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, dp_a[i] + dp_b[i]);
        return res;
    }
};
