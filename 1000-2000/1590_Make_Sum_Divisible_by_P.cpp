// https://leetcode.com/problems/make-sum-divisible-by-p/
// prefix sum + hash table

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        vector<int> pre(n); pre[0] = nums[0] % p;
        for (int i = 1; i < n; i++) pre[i] = (pre[i - 1] + nums[i]) % p;
        
        if (!pre[n - 1]) return 0;
        
        // cout << aim << endl; for (int i : pre) cout << i << endl;
        
        unordered_map<int, int> mod;
        int res = n, aim = pre[n - 1];
        for (int i = 0; i < n; i++) {
            int pmod = pre[i];
            int s = (pmod >= aim) ? pmod - aim : pmod + p - aim;
            
            if (!s) res = min(res, i + 1);
            if (mod[s]) res = min(res, i - mod[s] + 1);
            
            mod[pre[i]] = i + 1;
        }
        
        if (res >= n) return -1;
        return res;    
    }
};
