// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20
// recursion

class Solution {
public:
    int res;

    void recur(vector<int>& nums, int sum, int st) {
        for (int i = st; i < nums.size(); i++) {
            res += (sum ^ nums[i]);
            recur(nums, (sum ^ nums[i]), i + 1);
        }
    }

    int subsetXORSum(vector<int>& nums) {
        res = 0;
        recur(nums, 0, 0);
        return res;
    }
};
