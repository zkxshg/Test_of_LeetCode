// https://leetcode.com/problems/powerful-integers/
// branch-and-bound
class Solution {
public:
    unordered_map<int, bool> ex;
    
    void search(int x, int xi, int y, int yi, int bound, vector<int>& res) {
        int sum = pow(x, xi) + pow(y, yi);
        if (sum <= bound) {
            if (ex[sum]) {
                if (x == y) return;
            }
            else {
                res.push_back(sum); ex[sum] = true;
            }
            
            if (x > 1) search(x, xi + 1, y, yi, bound, res);
            if (y > 1) search(x, xi, y, yi + 1, bound, res);
        }
    }
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        ex.clear();
        vector<int> res;
        search(x, 0, y, 0, bound, res);
        return res;
    }
};
