// https://leetcode.com/problems/count-all-possible-routes/description/
// DP

class Solution {
public:
    #define locs locations
    #define ll long long
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locs.size();
        ll ub = 1e9 + 7;

        vector<vector<int> > preDiv(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                preDiv[i][j] = abs(locs[i] - locs[j]);
                preDiv[j][i] = abs(locs[i] - locs[j]);
            }
        }

        vector<vector<ll> > dp(fuel + 1, vector<ll>(n));
        dp[fuel][start] = 1;

        for (int i = fuel - 1; i >= 0; i--) { cout << i << ": "; 

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int div = preDiv[j][k]; 
                    if (j == k || i + div > fuel) continue;

                    dp[i][j] = (dp[i][j] + dp[i + div][k]) % ub;
                }
                cout << dp[i][j] << ",";
            } cout << endl;
            
        }
        
        ll res = 0;
        for (int i = 0; i <= fuel; i++) res = (res + dp[i][finish]) % ub;
        return res;
;
    }
};
