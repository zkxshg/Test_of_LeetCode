// https://leetcode.com/problems/longest-consecutive-sequence/
// Union Find
class Solution {
public:
    unordered_map<int, int> pre;
    
    int ances(int a) {
        if(pre[a] != a) return ances(pre[a]);
        return a;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(); if (n < 2) return n;
        
        pre.clear();
        for (int i : nums) pre[i] = i;
            
        for (int i : nums) {
            if (pre.find(i - 1) != pre.end()) pre[i] = pre[i - 1];
            if (pre.find(i + 1) != pre.end()) pre[i + 1] = pre[i];
        }
        
        int res = 1;
        for (int i : nums) 
            if (pre.find(i + 1) == pre.end() &&  pre.find(i - 1) != pre.end())
                res = max(res, i - ances(i) + 1);
        
        return res;
    }
};
