// https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
// prefix sum

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pre(n); pre[0] = arr[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + arr[i];
        
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j += 2) res += pre[j] - (i > 0 ? pre[i - 1] : 0);
        }
        
        return res;
    }
};
