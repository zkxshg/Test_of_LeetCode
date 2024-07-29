// https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29
// DP

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), res = 0;

        vector<int> incDP(n);
        vector<int> decDP(n);

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (rating[i] > rating[j]) {
                    incDP[i]++;
                    res += incDP[j];
                }
                else if (rating[i] < rating[j]) {
                    decDP[i]++;
                    res += decDP[j];
                }
            }
        }

        return res;
    }
};
