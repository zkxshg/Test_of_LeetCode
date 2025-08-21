// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
// hash table

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(); if (n < 2) return -1;
        
        int res = 100001;
        unordered_map<int, int> pre;
        for (int i = 0; i < n; i++) {
            if (pre[cards[i]]) res = min(res, i + 2 - pre[cards[i]]);
            pre[cards[i]] = i + 1;
            
        } 
        if (res > 100000) return -1;
        return res;
    }
};
