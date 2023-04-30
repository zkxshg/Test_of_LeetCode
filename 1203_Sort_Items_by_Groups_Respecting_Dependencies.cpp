// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
// Graph + Topological sorting

class Solution {
public:
    #define bt beforeItems
    void print2D(vector<vector<int>>& M) {
        int m = M.size();

        for (int i = 0; i < m; i++) {
            cout << i << ":";
            for (int j = 0; j < M[i].size(); j++) {
                cout << M[i][j]; if (j < M[i].size() - 1) cout << ",";
            }
            cout << endl;
        }
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, set<int>> path;
        unordered_map<int, int> inPath;
        
        unordered_map<int, set<int>> pathG;
        unordered_map<int, int> inPathG;
        
        unordered_map<int, int> GNum;
        
        for (int i = 0; i < n; i++) {
            if (group[i] >= 0) GNum[group[i]]++;
            else GNum[m]++;
            
            if (!bt[i].empty()) {
                for (int bef : bt[i]) { 
                    // Add node path
                    path[bef].insert(i); 
                    inPath[i]++;
                    
                    // Add group path
                    if (group[i] >= 0 && group[bef] != group[i]) { 
                        pathG[group[bef]].insert(group[i]);
                        inPathG[group[i]]++;
                    } 
                }
            }
        }
        
        vector<int> res;
        vector<vector<int> > S(m + 1);
        vector<int> SG;
        unordered_map<int, int> GRec = GNum;
        
        // Initialize nodes set
        for (int i = 0; i < n; i++) {
            if (!inPath[i]) {
                if (group[i] < 0) S[m].push_back(i);
                else S[group[i]].push_back(i);
            }
        }

        for (int i = 0; i < m; i++)
            if (inPathG[i] <= 0 && GNum[i] > 0) SG.push_back(i);
        
        int resNum = 0;
        while (!S[m].empty() || !SG.empty()) {
            //print2D(S);
            //cout << "SG = "; for (int i : SG)  cout << i << ","; cout << endl;
            
            // seach -1
            while (!S[m].empty()) {
                int i = S[m].back(); S[m].pop_back(); GNum[m]--;
                
                res.push_back(i); resNum++;
                
                for (int j : path[i]) {
                    inPath[j]--; 
                    if (group[j] >= 0 && group[j] != group[i]) {
                        inPathG[group[j]]--;
                        if (!inPathG[group[j]]) SG.push_back(group[j]);
                    }
                    
                    if (!inPath[j]) {
                        if (group[j] < 0) S[m].push_back(j);
                        else S[group[j]].push_back(j); 
                    }
                }
            }
            
            // select one group
            if (SG.empty()) break;
            
            int g = SG.back(); SG.pop_back();
            while (!S[g].empty()) {
                int i = S[g].back(); S[g].pop_back(); GNum[g]--;
                
                res.push_back(i); resNum++; 
                
                for (int j : path[i]) {
                    inPath[j]--;
                    if (group[j] >= 0 && group[j] != group[i]){
                        inPathG[group[j]]--;
                        if (!inPathG[group[j]]) SG.push_back(group[j]);
                    } 
                    
                    if (!inPath[j]) {
                        if (group[j] < 0) S[m].push_back(j);
                        else S[group[j]].push_back(j);
                    }
                }
            }
            
            if (GNum[g] > 0) return {}; // no solution
            //else {
            //    for (int nexG : pathG[g]) {
            //        inPathG[nexG].erase(g);
            //        if (inPathG[nexG].empty()) SG.push_back(nexG);
            //    }   
            //}
            
            // for (int i = 0; i < m; i++)
            //    if (inPathG[i] <= 0 && GNum[i] > 0) SG.push_back(i);
            
            //cout << "res = "; for (int i : res) cout << i << ","; cout << endl;
        }
        
        if (resNum < n) return {};
        
        return res;
    }
};
