// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/submissions/
// DP

class Solution {
public:
    #define mul multipliers
    #define lb INT_MIN
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = mul.size();
        
        vector<int> pos(n, lb);
        pos[n - 1] = mul[0] * nums[n - 1];
        
        vector<int> neg(n, lb);
        neg[0] = mul[0] * nums[0];
        
        for (int i = 1; i < m; i++) {
            vector<int> temPos(n, lb);
            vector<int> temNeg(n, lb);
            
            for (int j = 0; j < n; j++) {
                if (j > i && j < n - 1 - i) continue;

                // Pos 
                int nex = j + 1;
                int pre = (i - 1) - (n - nex);
                if (nex < n && pos[nex] > lb)  
                    temPos[j] = max(temPos[j], pos[nex] + mul[i] * nums[j]);
                
                if (pre >= 0 && neg[pre] > lb)  
                    temPos[j] = max(temPos[j], neg[pre] + mul[i] * nums[j]);
                    
                // Neg
                pre = j - 1;
                nex = n - (i - j);
                if (pre >= 0 && neg[pre] > lb)  
                    temNeg[j] = max(temNeg[j], neg[pre] + mul[i] * nums[j]);
                if (nex < n && pos[nex] > lb)
                    temNeg[j] = max(temNeg[j], pos[nex] + mul[i] * nums[j]);
                
                //cout << "(" << i << "," << j << ")" << dp[i - 1][pre] 
                // << ":" << dp[i - 1][nex] << endl; 
            }
            pos = temPos;
            neg = temNeg;
        }
        int ind = 2;
        //for (int i = 0; i < n; i++) cout << pos[ind][i] << ","; cout << endl;
        //for (int i = 0; i < n; i++) cout << neg[ind][i] << ","; cout << endl;
        
        int res = lb;
        for (int i = 0; i < n; i++) res = max(res, pos[i]);
        for (int i = 0; i < n; i++) res = max(res, neg[i]);
        return res;
    }
};
