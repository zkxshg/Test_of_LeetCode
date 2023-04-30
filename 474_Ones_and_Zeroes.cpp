// https://leetcode.com/problems/ones-and-zeroes/
// DP: O(l*m*n)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
	    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        
	    for(auto& str : strs) {          
		    int zeros = countZeros(str), ones = str.size() - zeros; 
            
		    for(int i = m; i >= zeros; i--)
			    for(int j = n; j >= ones; j--)                    
				    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1); 
            
	    }
	    return dp[m][n];
    }
    
    int countZeros(string& str) {
        int count = 0;
        for (char ch : str) if (ch == '0') count++;
        return count;
    }
};

// greedy: O(l^2)
class Solution {
public:
    static int cmp(string& a, string& b) {
        return a.size() < b.size();
    }   
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        
        sort(strs.begin(), strs.end(), cmp);
        
        vector<int> leftM(len, 0);
        vector<int> leftN(len, 0);
        vector<int> maxSize(len, 0);
        
        int couM_0 = countZeros(strs[0]);
        leftM[0] = m - couM_0; 
        leftN[0] = n - (strs[0].size() - couM_0);
        if (leftM[0] >= 0 && leftN[0] >= 0) maxSize[0] = 1;
        
        int res = maxSize[0];
        for (int i = 1; i < len; i++) {
            int couM_i = countZeros(strs[i]);
            int couN_i = strs[i].size() - couM_i;
            
            if (couM_i <= m && couN_i <= n) {
                maxSize[i] = 1; leftM[i] = m - couM_i; leftN[i] = n - couN_i;
            }
            else continue;
            
           int ml = 0, mlm = 0, mln = 0;
           for (int j = 0; j < i; j++) {
               
               if (leftM[j] >= couM_i && leftN[j] >= couN_i) {
                   
                   if (maxSize[j] + 1 > ml) {
                       ml = maxSize[j] + 1; 
                       mlm = leftM[j]; 
                       mln = leftN[j]; 
                   }
                   else if (maxSize[j] + 1 == ml && mlm + mln < leftM[j] + leftN[j]) {
                       leftM[j] = mlm; leftN[j] = mln;
                   }
                   
               }
           }
            
            if (ml > 0) {
                maxSize[i] = ml; leftM[i] = mlm - couM_i;  leftN[i] = mln - couN_i;
            }
            res = max(maxSize[i], res);
        }
        
        return res;
        
    }
    
    int countZeros(string& str) {
        int count = 0;
        for (char ch : str) if (ch == '0') count++;
        return count;
    }
};
