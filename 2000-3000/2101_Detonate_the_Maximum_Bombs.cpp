// https://leetcode.com/problems/detonate-the-maximum-bombs/
// Geometry + Graph + DFS

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, set<int>> paths;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                
                double dist = sqrt(double(x1 - x2) * (x1 - x2) + double(y1 - y2) * (y1 - y2));
                
                if (r1 >= dist) paths[i].insert(j);
                if (r2 >= dist) paths[j].insert(i);
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            set<int> visited;
            set<int> nex; nex.insert(i);
            
            int lres = 0;
            while (!nex.empty()) {
                int cir = *nex.begin();
                nex.erase(cir);
                    
                visited.insert(cir); lres++;
                
                for (int p : paths[cir]) {
                    if (!visited.count(p)) nex.insert(p);
                }
            }
            
            res = max(res, lres);
        }
        
        return res;
    }
};
