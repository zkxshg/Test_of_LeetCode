//https://leetcode.com/problems/check-if-it-is-a-straight-line/
// math

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int num = coordinates.size();
        if (num == 2) return true;
        
        double k, b;
        bool vertical = false;
        
        int x1 = coordinates[0][0], x2 = coordinates[1][0];
        int y1 = coordinates[0][1], y2 = coordinates[1][1];
        
        if (x1 == x2) vertical = true;
        else k = (y1 - y2) / (x1 - x2);
        
        if (vertical) b = x1;
        else b = y1 - k*x1;
        
        if (vertical){
            for (int i = 2; i < num; i++){
                if (coordinates[i][0] != b) return false;
            }
        }
        else{
            for (int i = 2; i < num; i++){
                if (coordinates[i][1] != k * coordinates[i][0] + b) return false;
            }
        }
        return true;
    }
};
