// https://leetcode.com/problems/course-schedule-ii/
// Graph + Topological sorting

class Solution {
public:
    #define prr prerequisites
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int p = prerequisites.size();
        
        unordered_map<int, set<int> > paths;
        unordered_map<int, int> inLine;
        
        for (auto& v : prr) {
            paths[v[1]].insert(v[0]);
            inLine[v[0]]++;
        }
        
        vector<int> res;
        vector<int> S;
        
        for (int i = 0; i < numCourses; i++)
            if (!inLine[i])
                S.push_back(i);
        
        while (!S.empty()) {
            int n = S.back();
            
            res.push_back(n); S.pop_back();
            
            for (auto& m : paths[n]) {
                if (inLine[m]) inLine[m]--;
                else continue;
                
                if (!inLine[m]) S.push_back(m);
            }     
        }
        
        if (res.size() < numCourses) return {};
        
        return res;
    }
};
