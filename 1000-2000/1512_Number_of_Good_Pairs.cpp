// https://leetcode.com/problems/number-of-good-pairs/
// hash table

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> fre;
        for (int i : nums) {
            res += fre[i]; fre[i]++;
        }
        return res;
    }
};
