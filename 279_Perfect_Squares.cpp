// DP
class Solution {
public:
    int numSquares(int n) {
        vector<int> resN(n + 1); 
        resN[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int sq = sqrt(i);
            int tem = n;
            for (int j = 1; j <= sq; j++) tem = min(tem, resN[i - j * j] + 1);
            resN[i] = tem;
        }
        
        return resN[n];
    }
};
