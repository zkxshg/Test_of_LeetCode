// https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Array

class Solution {
public:
    #define Q queries
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = Q.size();
        
        vector<int> even(n); int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                 sum += nums[i]; even[i] = 1;
            } 
        }
        
        vector<int> res;
        for (int i = 0; i < m; i++) {
            int v = Q[i][0], ind = Q[i][1];
            
            if (even[ind]) sum -= nums[ind];
            
            nums[ind] += v;
            
            if (nums[ind] % 2) even[ind] = 0;
            else {
                even[ind] = 1; sum += nums[ind];
            }
            
            res.push_back(sum);
        }
        
        return res;
    }
};
