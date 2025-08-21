// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/?envType=daily-question&envId=2023-10-10
// Greedy + Sliding Window
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int st = 0, en = 0, maxCou = 1, dup = 0;

        sort(nums.begin(), nums.end());

        while (en < n) {
            if (nums[en] - nums[st] <= n - 1) {
                if (en > st && nums[en] == nums[en - 1]) dup++;
                maxCou = max(maxCou, en - st + 1 - dup);
                en++;
            }
            else {
                if (nums[st] == nums[st + 1]) dup--;
                st++;
            }
        }

        return n - maxCou;
    }
};
