// 3487. Maximum Unique Subarray Sum After Deletion
// Link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
// Lang: C++
// Date: 2025-08-21 20:54:34.716 UTC

class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> fre;
        int res = 0, add = 0;
        while (!nums.empty()) {
            if (!fre[nums.back()] && nums.back() > 0)  {
                res += nums.back(); add++;
            }
            fre[nums.back()]++;
            if (nums.back() <= 0) {
                if (add <= 0) res += nums.back();
                break;
            }
            nums.pop_back();
        }
        return res;
    }
};
