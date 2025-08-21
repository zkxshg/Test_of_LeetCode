// https://leetcode.com/problems/card-flipping-game/
// hash table

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        
        set<int> cand; unordered_map<int, int> good;
        
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) good[fronts[i]]++;
            cand.insert(fronts[i]); cand.insert(backs[i]);
        } 
        
        int res = 0;
        for (auto& i : cand) {
            if (!good[i]) {res = i; break;}
        }
        
        return res;
    }
};
