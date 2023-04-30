// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
// greedy

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        double mid;
        if (n % 2) mid = nums[n / 2];
        else mid = double(nums[n / 2 - 1] + nums[n / 2]) / 2;
        
        // cout << mid << endl;
        
        vector<int> sll;
        vector<int> lge;
        for (int i : nums) {
            if (i < mid) sll.push_back(i);
            else lge.push_back(i);
        }
        
        vector<int> res;
        while (res.size() < n) {
            if (!sll.empty()) {
                res.push_back(sll.back()); sll.pop_back();
            }
            if (!lge.empty()) {
                res.push_back(lge.back()); lge.pop_back();
            }
        }
        
        return res;
        
    }
};
