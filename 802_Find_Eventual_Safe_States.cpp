// https://leetcode.com/problems/find-eventual-safe-states/
// Topological Sort

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        unordered_map<int, set<int>> outDeg;
        unordered_map<int, set<int>> income;
        
        for (int i = 0; i < n; i++) 
            for (int en : graph[i]) {
                outDeg[i].insert(en);
                income[en].insert(i);
            }
                
        vector<int> zero; set<int> more;
        
        for (int i = 0; i < n; i++) {
            if (outDeg[i].size() < 1) zero.push_back(i);
            else more.insert(i); 
        }

        vector<int> res;
        while (!zero.empty()) { 
            int t = zero.back(); zero.pop_back();
            
            vector<int> rm;
            for (int aim : income[t]) { 
                if (!more.count(aim)) continue;
                
                if (outDeg[aim].count(t)) {
                    outDeg[aim].erase(t);
 
                    if (outDeg[aim].size() < 1) rm.push_back(aim);
                }
            }
            
            for (int aim : rm) {
                more.erase(aim); zero.push_back(aim);
            }
            
            res.push_back(t);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
}; 
