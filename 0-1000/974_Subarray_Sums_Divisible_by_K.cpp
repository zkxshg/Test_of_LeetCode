// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// prefix sum

class Solution {
public:
    int sigma(int k) {
        int res = 0;
        for (int i = k; i > 0; i--) res += i;
        return res;
    }
    
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pre(n); pre[0] = nums[0];
        vector<int> kmod(k); 
        if ((pre[0]) % k < 0) kmod[pre[0] % k + k]++;
        else kmod[pre[0] % k]++;
        
        for (int i = 1; i < n; i++) {
            pre[i] = (pre[i - 1] + nums[i]); 
            
            if ((pre[i]) % k < 0) kmod[pre[i] % k + k]++;
            else kmod[pre[i] % k]++;
        }
        
        //for (int i : kmod) cout << i << endl;
        int res = sigma(kmod[0]);
        for (int i = 1; i < k; i++) res += sigma(kmod[i] - 1);
        return res;
    }
};
