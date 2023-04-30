// https://leetcode.com/problems/longest-uncommon-subsequence-ii/
// greedy

class Solution {
public:
    bool ifContain(vector<string>& strs, int aim) {
        bool contain = false;
        
        for (int i = 0; i < strs.size(); i++) {
            if (i == aim) continue;
            
            if (strs[i].size() < strs[aim].size()) continue;
            
            string& A = strs[i];
            string& P = strs[aim];
            
            int apos = 0, ppos = 0;
            while (apos < A.size() && ppos < P.size()) {
                if (A[apos] == P[ppos]) ppos++;
                apos++;
            }
            
            if (ppos == P.size()) return true;
        }
        
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        int res = -1, n = strs.size();
        
        for (int i = 0; i < n; i++) 
            if (!ifContain(strs, i)) 
                res = max(res, int(strs[i].size()));
        
        return res;
    }
};
