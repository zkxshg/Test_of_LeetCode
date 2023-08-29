// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/
// prefix sum

class Solution {
public:
    #define cus customers

    int bestClosingTime(string customers) {
        int n = cus.size();

        vector<int> Ay(n + 1);
        vector<int> An(n + 1);
        

        for (int i = 1; i <= n; i++) {
            Ay[i] = Ay[i - 1];
            An[i] = An[i - 1];

            if (cus[i - 1] == 'Y') Ay[i]++;
            else An[i]++;
        }

        int res = n, allY = Ay[n], allN = An[n], pos = 0;

        for (int i = 0; i <= n; i++) {
            int tem = An[i] + (allY - Ay[i]);

            if (tem < res) {
                res = tem; pos = i;
            }
        }

        return pos;
    }
};
