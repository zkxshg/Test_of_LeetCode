// https://leetcode.com/problems/redundant-connection-ii/
// Graph + DFS

class Solution {
public:
    vector<int> id;
    vector<int> low;
    unordered_map<int, vector<int> > E;
    unordered_map<int, vector<int> > inE;
    
    vector<pair<int, int> > cand;
    vector<pair<int, int> > temCand;
    
    int index, childNum;   
    
     void dfs(int tem, int pre) {
         id[tem] = index; 
         
         if (tem == pre) low[tem] = tem;
         else low[tem] = pre;
         
         index++; childNum++;
        
        for (int next : E[tem]) {
            if (!id[next]) dfs(next, tem);
            else {
                int trace = tem;
                while (low[trace] != trace && low[trace] != next) trace = low[trace];
                
                if (low[trace] == next) temCand.push_back({tem, next});
                else {
                    for (int i : inE[next]) temCand.push_back({i, next});
                }
            }
        }
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        id.resize(n + 1); low.resize(n + 1);
        index = 1;
        
        E.clear();
        for (vector<int> v : edges)  {
            E[v[0]].push_back(v[1]);
            inE[v[1]].push_back(v[0]);
        }
        
        
        cand.clear();
        
        for (int i = 1; i <= n; i++) {
            id.resize(0); id.resize(n + 1);
            low.resize(0); low.resize(n + 1);

            index = 1; childNum = 0;
            temCand.clear();
                
            dfs(i, i);
            
            if (childNum >= n) {
                for (auto& p : temCand) cand.push_back(p);
            }
            // cout << i << ":" << childNum << endl;
        }
        
        // for (auto& p : cand)  cout << p.first << ":" << p.second << endl;
        
        unordered_map<int, unordered_map<int, int> > order;
        for (int i = 0; i < n; i++) 
            order[edges[i][0]][edges[i][1]] = i + 1;
       
        int res = 0;
        for (auto& p : cand) res = max(res, order[p.first][p.second]);
        
        return edges[res - 1];
    }
};
