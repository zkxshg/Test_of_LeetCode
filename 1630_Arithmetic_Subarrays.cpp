// https://leetcode.com/problems/arithmetic-subarrays/
// Sorting

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            int lb = l[i], rb = r[i];
            
            if (rb - lb < 2) {
                res[i] = true; continue;
            }
            
            vector<int> sub(nums.begin() + lb, nums.begin() + rb + 1);
            sort(sub.begin(), sub.end());
            
            int pre = sub[1] - sub[0]; res[i] = true;
            for (int j = 2; j <= rb - lb; j++) {
                if (sub[j] - sub[j - 1] != pre) {
                    res[i] = false; break;
                }
            }
        }
        
        return res;
        
//         vector<vector<int> > div(n, vector<int>(n, -1));
//         vector<vector<int> > maxM(n, vector<int>(n, -1));
//         vector<vector<int> > minM(n, vector<int>(n, -1));
        
//         for (int i = 0; i < n - 1; i++) {
//             div[i][i + 1] = abs(nums[i] - nums[i + 1]);
//             maxM[i][i + 1] = max(nums[i], nums[i + 1]);
//             minM[i][i + 1] = min(nums[i], nums[i + 1]);
//         }
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 2; j < n; j++) {
//                 if (nums[j] - maxM[i][j - 1] == div[i][j - 1]) {
//                     div[i][j] = div[i][j - 1]; maxM[i][j] = nums[j];
                    
//                 }
//                 else if (minM[i][j - 1] - nums[j] == div[i][j - 1]) {
//                     div[i][j] = div[i][j - 1]; minM[i][j] = nums[j];
//                 }
//                 else {
//                     div[i][j] = -1; break;
//                 }
//             }
//         }
    }
};
