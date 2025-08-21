// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// hash table + sliding window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> fre;

        int n = nums.size(), st = 0, en = 1, res = 1; fre[nums[st]]++;

        while (en < n) {
            fre[nums[en]]++;

            if (fre[nums[en]] > k) {
                while (fre[nums[en]] > k) {
                    fre[nums[st]]--;
                    st++;
                }
            }

            res = max(res, en - st + 1);
            en++;  

            // cout << st << ":" << en << endl;
        }

        return res;
    }
};
