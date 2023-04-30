// https://leetcode.com/problems/minimum-genetic-mutation/
// BFS

class Solution {
public:
    bool ifMute(string& a, string& b) {
        int cou = 0;
        for (int i = 0; i < 8; i++) {
            if (a[i] != b[i]) cou++;
            if (cou > 1) return false;
        }
        return true;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        if (start == end) return 0;
        
        unordered_map<string, int> node; int ind = 1;
        unordered_map<int, string> nodeR;
        
        node[start] = ind; nodeR[ind] = start; ind++;
        
        for (string& s : bank) {
            if (node[s]) continue;
            node[s] = ind; nodeR[ind] = s; ind++;
        }
        
        if (!node[end]) return -1;
        
        unordered_map<int, set<int>> path;
        for (int i = 1; i < ind; i++) {
            for (int j = 1; j < ind; j++) {
                if (i == j || path[i].count(j)) continue;
                
                if (ifMute(nodeR[i], nodeR[j])) {
                    path[i].insert(j);
                    path[j].insert(i);
                }
            }
        }
        
        int step = 0; 
        vector<int> bfs; bfs.push_back(1);
        unordered_map<int, int> visited; visited[1]++;
        
        while (!bfs.empty()) {
            step++;
            
            vector<int> tem;
            
            for (int nd : bfs) {
                for (auto& nex : path[nd]) {
                    if (visited[nex]) continue;
                    
                    if (nodeR[nex] == end) return step;
                    
                    tem.push_back(nex); visited[nex]++;
                }
            }
            
            bfs = tem;
        }
        
        
        return -1;
        
    }
};
