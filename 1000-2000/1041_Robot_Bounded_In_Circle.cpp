// https://leetcode.com/problems/robot-bounded-in-circle/
// Exhaustive search
class Solution {
public:
    bool isRobotBounded(string instructions) {
        char direct = 'N';
        int HorDist = 0, VerDist = 0;
        
        for (char ch : instructions) {
            if (ch == 'L'|| ch == 'R') direct = turn(direct, ch);
            else {
                if (direct == 'N') VerDist++;
                else if (direct == 'S') VerDist--;
                else if (direct == 'W') HorDist++;
                else HorDist--;
            }
        }
        
        if (direct != 'N') return true; 
        if (HorDist == 0 && VerDist == 0) return true;
        return false;
    }
    
    char turn(char dir, char act) {
        if (dir == 'S') {
            if (act == 'L') return 'E';
            else return 'W';
        } 
        if (dir == 'W') {
            if (act == 'L') return 'S';
            else return 'N';
        }
        if (dir == 'N') {
            if (act == 'L') return 'W';
            else return 'E';
        }
        if (act == 'L') return 'N';
        return 'S';
    }
};
