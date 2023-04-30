// https://leetcode.com/problems/largest-plus-sign/
// DP

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        if (n == 1) return 0;
        
        vector<vector<int>> upM(n, vector<int>(n, 1));
        for (auto& v : mines) upM[v[0]][v[1]] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                if (upM[i - 1][j] && upM[i][j])
                    upM[i][j] = upM[i - 1][j] + 1;
        
        vector<vector<int>> downM(n, vector<int>(n, 1));
        for (auto& v : mines) downM[v[0]][v[1]] = 0;
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
                if (downM[i + 1][j] && downM[i][j])
                    downM[i][j] = downM[i + 1][j] + 1;
        
        vector<vector<int>> leftM(n, vector<int>(n, 1));
        for (auto& v : mines) leftM[v[0]][v[1]] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                if (leftM[j][i - 1] && leftM[j][i])
                    leftM[j][i] = leftM[j][i - 1] + 1;
        
        vector<vector<int>> rightM(n, vector<int>(n, 1));
        for (auto& v : mines) rightM[v[0]][v[1]] = 0;
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
                if (rightM[j][i + 1] && rightM[j][i])
                    rightM[j][i] = rightM[j][i + 1] + 1;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (upM[i][j]) {
                    int temR = min(upM[i][j], downM[i][j]);
                    temR = min(temR, leftM[i][j]);
                    temR = min(temR, rightM[i][j]);
                    res = max(res, temR);
                }
            }
        }
        
        return res;
    }
};
