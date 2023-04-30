// https://leetcode.com/problems/minimum-sideway-jumps/
// DP
class Solution {
public:
    #define ob obstacles
    int minSideJumps(vector<int>& obstacles) {
        int n = ob.size();
        
        vector<vector<int> > sucT(3, vector<int>(n, n+1)); 
        for (int i = n - 2; i > 0; i--) {
            for (int j = 0; j < 3; j++) sucT[j][i - 1] = sucT[j][i];
            if (ob[i] > 0) sucT[ob[i] - 1][i - 1] = i;
        }

        int st = 2, jum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (ob[i + 1] != st) continue; // no obstacle
            else {
                if (ob[i] > 0) { // one choice
                    st = 6 - st - ob[i]; jum++;
                }
                else { // two choice
                    if (st == 1) {
                        if (sucT[1][i] > sucT[2][i]) st = 2;
                        else st = 3;
                    }
                    else if (st == 2) {
                        if (sucT[0][i] > sucT[2][i]) st = 1;
                        else st = 3;
                    }
                    else {
                        if (sucT[0][i] > sucT[1][i]) st = 1;
                        else st = 2;
                    }
                    jum++;
                }
            }
        }
        return jum;
    }
};
