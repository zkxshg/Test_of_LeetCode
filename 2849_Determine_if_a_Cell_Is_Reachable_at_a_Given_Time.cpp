// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
// Math

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int row = abs(sx - fx), col = abs(sy - fy);

        int ub = row + col, lb = max(row, col); cout << lb << ":" << ub << endl;

        // if (t <= ub && t >= lb) return true;
        // else if (t > ub) {
        //     int div = t - ub;
        //     if (div % 2 == 0 || div % 3 == 0) return true;
        // }
        if (ub < 1) {
            if (t < 1) return true;
            if (t < 2) return false;
        }
        
        if (t >= lb) return true;

        return false;
    }
};
