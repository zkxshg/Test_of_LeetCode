// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// BFS

class Solution {
public:
    int m, n;
    
    bool isExit(int x, int y) {
        if (x == 0 || x == m - 1) return true;
        if (y == 0 || y == n - 1) return true;
        return false;
    }
        
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size(); n = maze[0].size();
        
        vector<pair<int, int> > bfs; bfs.push_back({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '-';
        
        int step = 0; bool reach = false;
        while (!reach && !bfs.empty()) {
            step++;
            
            vector<pair<int, int> > tem;
            
            for (auto& p : bfs) {
                int x = p.first, y = p.second;
                
                if (x > 0 && maze[x - 1][y] == '.') {
                    if (isExit(x - 1, y)) {
                        reach = true; break;
                    }
                    maze[x - 1][y] = '-';
                    tem.push_back({x - 1, y});
                }
                
                if (y > 0 && maze[x][y - 1] == '.') {
                    if (isExit(x, y - 1)) {
                        reach = true; break;
                    }
                    maze[x][y - 1] = '-';
                    tem.push_back({x, y - 1});
                }
                
                if (x < m - 1 && maze[x + 1][y] == '.') {
                    if (isExit(x + 1, y)) {
                        reach = true; break;
                    }
                    maze[x + 1][y] = '-';
                    tem.push_back({x + 1, y});
                }
                
                if (y < n - 1 && maze[x][y + 1] == '.') {
                    if (isExit(x, y + 1)) {
                        reach = true; break;
                    }
                    maze[x][y + 1] = '-';
                    tem.push_back({x, y + 1});
                }
                
            }
            
            bfs = tem;
        }
        
        if (!reach) return -1;
        
        return step;
    }    
};
