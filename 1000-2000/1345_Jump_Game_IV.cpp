// https://leetcode.com/problems/jump-game-iv/
// BFS
class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int> q{{0}};
        const int n = arr.size();        
        vector<int> visited(n, 0);
        visited[0]=1;        
        unordered_map<int, vector<int>> equals;
        for(int i = 0; i < n; i++) equals[arr[i]].push_back(i);                
        for(int step = 0;!q.empty(); step++){
            for(int i = q.size(); i>0;i--){
                auto cur = q.front(); q.pop();
                if(cur == n - 1) return step;                
                auto& nexts = equals[arr[cur]];nexts.push_back(cur-1); nexts.push_back(cur+1);
                for(int next: nexts)
                    if(next >=0 && next < n && !visited[next]) q.push(next), visited[next]=1;                     
                
                nexts.clear();           
            }
        }
        return n - 1;
    }
};

// Dijkstra
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size(); if (len == 1) return 0;
        
        vector<int> dist(len, pow(10, 9));
        
        dist[1] = 1;
        
        for (int j = 1; j < len; j++) {
            if (arr[0] == arr[j]) dist[j] = 1;
        } 
        
        unordered_map<int, int> path; path[0] = 1;

        while (dist[len - 1] > 6 * pow(10, 5)) {
            int minNode = 0, minLen = pow(10, 9);
            
            for (int j = 1; j < len; j++) {
                if (!path[j]) {
                    if (dist[j] < minLen) {
                        minNode = j; minLen = dist[j];
                    }
                }
            }
            
            path[minNode] = 1;
            
            if (!path[minNode - 1]) {
                dist[minNode - 1] = min(dist[minNode] + 1, dist[minNode - 1]);
            }
            if (minNode < len - 1 && !path[minNode + 1]) {
                dist[minNode + 1] = min(dist[minNode] + 1, dist[minNode + 1]);
            }
            
            for (int j = 1; j < len; j++) {
                if (!path[j]) {
                    if (j != minNode && arr[j] == arr[minNode]) {
                        dist[j] = min(dist[minNode] + 1, dist[j]);
                    }
                }
            }
        }
        
        return dist[len - 1];
    }
};
