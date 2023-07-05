// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
// Sliding window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int pre = 0;
        while (pre < n && nums[pre] == 0) pre++;
        if (pre >= n - 1) return 0;

        int suc = pre + 1;

        int res = 0;
        while (suc < n) {
            int preLen = 0, sucLen = 0;
            while (suc < n && nums[suc] == 1) suc++;

            // [pre, suc)
            if (suc >= n) {
                if (pre > 0) res = max(res, n - pre);
                else res = max(res, n - pre - 1); // [pre, n - 1]
                break;
            }
            preLen = suc - pre;
            suc++;

            // (pre + preLen, suc)
            while (suc < n && nums[suc] == 1) suc++;
            if (suc >= n) {
                res = max(res, n - pre - 1); // [pre, pre + preLen) + (pre + preLen, n - 1] 
                break;
            }
            sucLen = suc - pre - preLen - 1;

            res = max(res, sucLen + preLen);
 
            //cout << "[" << pre << "," << pre + preLen << ") + (" 
            //   << pre + preLen << "," << suc << ") = " << sucLen + preLen << endl;
            //cout << preLen << "+" << sucLen << endl;

            if (sucLen  == 0) {
                pre = suc;
                while (pre < n && nums[pre] == 0) pre++;
                if (pre >= n - 1) break;
                suc = pre + 1;
            }
            else {
                pre = pre + preLen + 1;
            }
        }

        return res;
    }
};
