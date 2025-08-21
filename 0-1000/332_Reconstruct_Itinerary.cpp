// https://leetcode.com/problems/reconstruct-itinerary/
// Graph -> Eulerian Circuit -> Hierholzer's algorithm

class Solution {
public:
    unordered_map<string, vector<string>> path;
    unordered_map<string, int> inDeg;
    unordered_map<string, int> outDeg;
    // set<string> nodes;
    vector<string> res;
    
    void dfs(string a) {
        string nex = a;
        
        vector<string> st; st.push_back(a);
        
        // First DFS
        while (outDeg[nex] > 0) {
            // 1 visit neighbor node
            string tem = path[nex].back();
            
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
            string bk = st.back();
            
            if (outDeg[bk] > 0) dfs(bk);
            else res.push_back(bk);

            st.pop_back();
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        path.clear(); inDeg.clear(); outDeg.clear(); res.clear();
        // nodes.clear();
        
        for (auto& v : tickets) {
            string s1 = v[0], s2 = v[1];
            // nodes.insert(s1); nodes.insert(s2);
            
            path[s1].push_back(s2);
            
            inDeg[s2]++; outDeg[s1]++;
        }
        // for (auto& p : outDeg) cout << p.first << ":" << p.second << endl;
        
        for (auto& p : path) sort(p.second.begin(), p.second.end(), greater<string>());
        
        // Find the start point
        string start = "JFK";
        
        // bool circ = true; // if Eulerian Circuit
        // for (auto& s : nodes) {
        //    if (inDeg[s] != outDeg[s] && outDeg[s] > inDeg[s]) { // Semi-Eulerian Circuit
        //        circ = false; 
        //        break;
        //    }
        //}
        //if (circ) start = tickets[0][0]; // Eulerian Circuit, random select
        // cout << start << endl;
        
        // Find Eulerian path
        dfs(start);
        
        reverse(res.begin(), res.end());
        return res;
    }
};
