// https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// BFS

class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> bfs;
        
        for (int i = 1; i <= 9; i++) bfs.insert(i);
        
        int lv = 1;
        while (lv < n) {
            set<int> nex;
            
            for (int num : bfs) {
                int r = num % 10;
                if (r - k >= 0) nex.insert(num * 10 + (r - k));
                if (r + k <= 9) nex.insert(num * 10 + (r + k));
            }
            
            bfs = nex; lv++;
        }
        
        vector<int> res; for (int i : bfs) res.push_back(i);
        return res;
    }
};
