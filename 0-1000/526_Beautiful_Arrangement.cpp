// https://leetcode.com/problems/beautiful-arrangement/
// permutation
class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, nums);
    }
    int helper(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (n % nums[i] == 0 || nums[i] % n == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};

// DP
class Solution {
public:
    int countArrangement(int n) {
        if (n == 1) return 1;
        
        vector<vector<int> > arrs; arrs.push_back({1});
        
        for (int i = 2; i <= n; i++) {
            vector<vector<int> > tem;
            
            for (vector<int> arr : arrs) {
                for (int j = 0; j < i - 1; j++) {
                    if (i % max(j + 1, arr[j]) == 0) {
                        vector<int> tem2 = arr;
                        
                        tem2.push_back(tem2[j]); tem2[j] = i;
                        
                        tem.push_back(tem2);
                    }
                }
                
                vector<int> tem3 = arr;
                tem3.push_back(i);
                tem.push_back(tem3);
            }
  
            arrs = tem;
        }
        
        return arrs.size();
    }
};
