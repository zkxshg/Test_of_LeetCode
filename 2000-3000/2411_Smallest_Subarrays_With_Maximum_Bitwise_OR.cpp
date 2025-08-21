// 2411. Smallest Subarrays With Maximum Bitwise OR
// Link: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
// Lang: C++
// Date: 2025-08-21 20:53:30.085 UTC

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);
        vector<int> last(32, -1);

        for (int i = n - 1; i >= 0; --i) {
            unsigned x = static_cast<unsigned>(nums[i]);
            while (x) {
                int b = __builtin_ctz(x); 
                last[b] = i;
                x &= (x - 1);
            }

            int far = i;
            for (int b = 0; b < 32; ++b) {
                if (last[b] != -1) far = max(far, last[b]);
            }
            ans[i] = far - i + 1;
        }

        return ans;
    }
};
