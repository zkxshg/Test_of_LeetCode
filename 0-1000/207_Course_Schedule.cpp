// https://leetcode.com/problems/course-schedule/
// Graph + BFS

class Solution {
public:
    #define prr prerequisites
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int p = prerequisites.size();
        
        unordered_map<int, set<int> > paths;
        unordered_map<int, int> inLine;
        
        for (auto& v : prr) {
            paths[v[1]].insert(v[0]);
            inLine[v[0]]++;
        }
        
        vector<int> S; int numTake = 0;
        
        for (int i = 0; i < numCourses; i++) {
            if (!inLine[i]) {
                S.push_back(i); numTake++;
            }
        }
            
        
        while (!S.empty()) {
            int n = S.back(); S.pop_back();
            
            for (auto& m : paths[n]) {
                if (inLine[m]) inLine[m]--;
                else continue;
                
                if (!inLine[m]) {
                    S.push_back(m); numTake++;
                }
            }     
        }
        
        if (numTake == numCourses) return true;
        
        return false;
    }
};
