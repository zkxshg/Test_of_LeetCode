// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// DP

class Solution {
public:
    #define ll long long
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        
        unordered_map<int, map<long, long>> dp;
        
        for(int i = 0; i< nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                long cd = nums[i]; cd -= nums[j]; 
                
                if(dp[j][cd]) {
                    ans += dp[j][cd];
                    
                    dp[i][cd] += dp[j][cd] + 1;  
                }
                else dp[i][cd]++;     
            }
        }
        
        return ans;
    }
};

// DP + hash table
class Solution {
public:
    #define ll long long
    
    void print2D(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();

        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << M[i][j]; if (j < n - 1) cout << ",";
        }
        cout << endl;
        }
    }
    
    int subseq(vector<pair<int, int> >& divs, int n) {
        int m = divs.size();  
        
        vector<vector<int> > dp(n, vector<int>(n));
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            int x = divs[i].first, y = divs[i].second;
            
            dp[y][0]++;
            
            for (int j = 0; j < x; j++) {
                dp[y][j + 1] += dp[x][j]; res += dp[x][j];
            }
        }
           
        //print2D(dp);

        return res;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        
        vector<ll> dif(n - 1);
        for (int i = 0; i < n - 1; i++) {
            dif[i] = nums[i + 1]; dif[i] -= nums[i];
        }
        
        vector<vector<ll> > dp(n - 1, vector<ll>(n - 1, -1));
        dp[0][0] = dif[0];
        
        unordered_map<ll, vector<pair<int, int> > > divs;
        divs[dp[0][0]].push_back({0, 1});
        
        for (int i = 1; i < n - 1; i++) {
            dp[i][0] = dif[i];
            
            for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + dif[i];
            
            for (int j = 0; j <= i; j++) divs[dp[i][j]].push_back({i - j, i + 1});
        }
        //print2D(dp);
        
        int res = 0;
        for (auto& p : divs) {
            //cout << p.first << ":" << endl;
            if (p.second.size() > 1) res += subseq(p.second, n);
        }
            
        
        return res;
    }
};
