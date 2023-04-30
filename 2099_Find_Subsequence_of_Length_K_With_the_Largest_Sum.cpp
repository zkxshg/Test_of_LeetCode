// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// greedy

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> sn = nums;
        sort(sn.begin(), sn.end());
        
        unordered_map<int, int> fre;
        for (int i = 0; i < nums.size() - k; i++) fre[sn[i]]++;
        
        vector<int> res;
        for (int i : nums) {
            if (fre[i]) fre[i]--;
            else res.push_back(i);
        }
        return res;
    }
};
