// https://leetcode.com/problems/frog-jump/
// DP

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        if (stones[1] != 1) return false;
        
        unordered_map<int, int> sto;
        for (int i : stones) sto[i]++;
        
        unordered_map<int, set<int>> ks;
        
        ks[1].insert(1);
        
        for (int i = 1; i < n - 1; i++) {
            int pos = stones[i];
            
            for (const auto& k : ks[pos]) {
                if (k > 1 && sto[pos + k - 1]) ks[pos + k - 1].insert(k - 1);
                if (sto[pos + k]) ks[pos + k].insert(k);
                if (sto[pos + k + 1]) ks[pos + k + 1].insert(k + 1);
            }
            
        }
        
        return (!ks[stones.back()].empty());
    }
};
