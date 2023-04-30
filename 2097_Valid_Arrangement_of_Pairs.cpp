// https://leetcode.com/problems/valid-arrangement-of-pairs/submissions/
// Graph + Eulerian Circuit

class Solution {
public:
    unordered_map<int, vector<int>> path;
    unordered_map<int, int> inDeg;
    unordered_map<int, int> outDeg;
    
    set<int> nodes;
    vector<int> res;
    
    void dfs(int a) {
        int nex = a;
        
        vector<int> st; st.push_back(a);
        
        // First DFS
        while (outDeg[nex] > 0) {
            // 1 visit neighbor node
            int tem = path[nex].back();
            
            // 2 delete visited edge
            path[nex].pop_back();
            inDeg[tem]--; outDeg[nex]--;
            
            
            // 3 next node
            nex = tem;
            st.push_back(nex);
            
            // 4 back to start point
            if (nex == a) break;
        }
        // for (auto& s : st) cout << s << ","; cout << endl;
        
        // Find subtour
        while (!st.empty()) {
            int bk = st.back();
            
            if (outDeg[bk] > 0) dfs(bk);
            else res.push_back(bk);

            st.pop_back();
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Initialize
        path.clear(); inDeg.clear(); outDeg.clear(); res.clear();
        nodes.clear();
        
        // pairs to path
        for (auto& p : pairs) {
            int a = p[0], b = p[1];
            
            nodes.insert(a); nodes.insert(b);
            
            path[a].push_back(b);
            
            inDeg[b]++; outDeg[a]++;
        }
        

        // Find the start point
        int start = 1;
        
        bool circ = true; // if Eulerian Circuit
        
        for (auto& s : nodes) {
           if (inDeg[s] != outDeg[s] && outDeg[s] > inDeg[s]) { // Semi-Eulerian Circuit
               circ = false; start = s;
               break;
           }
        }
        
        if (circ) start = pairs[0][0]; // Eulerian Circuit, random select
        // cout << start << endl;
        
        // Find Eulerian path
        dfs(start);
        
        reverse(res.begin(), res.end());
        
        vector<vector<int> > pres;
        for (int i = 0; i < res.size() - 1; i++) pres.push_back({res[i], res[i + 1]});
        return pres;
        
    }
};
