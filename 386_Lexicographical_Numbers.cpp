// https://leetcode.com/problems/lexicographical-numbers/
// DFS

class Solution {
public:
    vector<int> res;
    int aim;
    
    
    void dfs(int pre, int lv) {
        if (pre <= aim) res.push_back(pre);
        else return;
        
        if (lv <= 0) return;
        
        for (int i = 0; i <= 9; i++) {
            int nex = pre * 10 + i;
            
            if (nex > aim) break;
            
            dfs(nex, lv - 1);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        res.clear(); aim = n;
        
        int lv = 0;
        while (n) {
            n /= 10; lv++;
        }
        
        for (int i = 1; i <= 9; i++) dfs(i, 4);
        
        return res;
    }
};
