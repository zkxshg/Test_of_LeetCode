//https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-01
// hash table + simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        sort(obstacles.begin(), obstacles.end());
        unordered_map<int, vector<int>> rowObstacles;   
        unordered_map<int, vector<int>> colObstacles; 
        
        
        // Fill the obstacle maps
        for (auto& obs : obstacles) {
            int x = obs[0];
            int y = obs[1];
            rowObstacles[x].push_back(y);
            colObstacles[y].push_back(x);
        }
        
        int x = 0, y = 0;  // Current position
        int d = 0;  // Current direction index (0: North, 1: East, 2: South, 3: West)
        int maxDistSq = 0;
        
        for (int command : commands) {
           // cout <<  directions[d].first << "," <<  directions[d].second << endl;

            if (command == -2) {  // Turn left
                d = (d + 3) % 4;
            } 
            else if (command == -1) {  // Turn right
                d = (d + 1) % 4;
            } 
            else {  // Move forward
                int startX = x, startY = y;
                int endX = x + directions[d].first * command;
                int endY = y + directions[d].second * command;

                //cout << "ST:" << x << ":" << y << endl;
                //cout << "EN: " << endX << ":" << endY << endl;
                
                bool blocked = false;
                
                if (d == 0) {  // Moving North
                    auto it = rowObstacles.find(x);
                    if (it != rowObstacles.end()) {
                        const vector<int>& obsCols = it->second;
                        auto pos = lower_bound(obsCols.begin(), obsCols.end(), startY + 1);
                        if (pos != obsCols.end() && *pos <= endY) {
                            endY = *pos - 1;
                        }
                    }
                } 
                else if (d == 1) {  // Moving East
                    auto it = colObstacles.find(y);
                    if (it != colObstacles.end()) {
                        const vector<int>& obsRows = it->second;
                        auto pos = lower_bound(obsRows.begin(), obsRows.end(), startX + 1);
                        if (pos != obsRows.end() && *pos <= endX) {
                            endX = *pos - 1;
                        }
                    } 
                } 
                else if (d == 2) {  // Moving South
                    auto it = rowObstacles.find(x);
                    if (it != rowObstacles.end()) {
                        const vector<int>& obsCols = it->second;
                        auto pos = lower_bound(obsCols.begin(), obsCols.end(), endY);
                        if (pos != obsCols.end() && *pos <= startY - 1) {
                            endY = *pos + 1;
                        }
                    }
                } 
                else if (d == 3) {  // Moving West
                    auto it = colObstacles.find(y);
                    if (it != colObstacles.end()) {
                        const vector<int>& obsRows = it->second;
                        auto pos = lower_bound(obsRows.begin(), obsRows.end(), endX);
                        if (pos != obsRows.end() && *pos <= startX - 1) {
                            endX = *pos + 1;
                        }
                    }
                }

                x = endX;
                y = endY;
                maxDistSq = max(maxDistSq, x * x + y * y);
            }
        }
        
        return maxDistSq;
    }
};
