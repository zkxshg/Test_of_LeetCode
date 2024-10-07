// https://leetcode.com/problems/shortest-path-with-alternating-colors/
// BFS

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int b = blueEdges.size(), r = redEdges.size();
        
        // Path
        unordered_map<int, vector<int>> RE;
        for (auto& v : redEdges) RE[v[0]].push_back(v[1]);
        
        unordered_map<int, vector<int>> BE;
        for (auto& v : blueEdges) BE[v[0]].push_back(v[1]);
        
        vector<int> res(n, -1); res[0] = 0;   // Result
        
        int num = 1;   // Visited number
        
        // record the visitor of red and blue
        unordered_map<int, int> visitR; unordered_map<int, int> visitB;
        visitR[0]++; visitB[0]++;
        
        // BFS
        vector<int> bfsR;
        for (int i : RE[0]) {
            bfsR.push_back(i);  visitR[i]++;

            if (res[i] < 0) {
               res[i] = 1; num++;  
            }
        }
        vector<int> bfsB;
        for (int i : BE[0]) {
            bfsB.push_back(i); visitB[i]++;

            if (res[i] < 0) {
               res[i] = 1; num++;  
            }
        }
        
        int step = 1;
        while ((!bfsR.empty() || !bfsB.empty()) && num < n) {
            step++;
            
            vector<int> temR; vector<int> temB;
            
            // RED
            for (int i : bfsR) {  
                for (int j : BE[i]) {
                    if (visitB[j]) continue;
                    
                    if (res[j] < 0) {
                        res[j] = step; num++;
                    }
                    
                    visitB[j]++; temB.push_back(j);
                }  
            }
            
            // BLUE
            for (int i : bfsB) {  
                for (int j : RE[i]) {
                    if (visitR[j]) continue;
                    
                    if (res[j] < 0) {
                        res[j] = step; num++;
                    } 
                    
                    visitR[j]++; temR.push_back(j);
                }  
            }
            
            bfsB = temB; bfsR = temR;
        }
        
        return res;
    }
};
