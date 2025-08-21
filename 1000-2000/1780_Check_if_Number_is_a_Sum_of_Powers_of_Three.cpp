// greedy
class Solution {
public:
    bool checkPowersOfThree(int n) {
        unordered_map<int, int> ps;
        
        while (n > 0) {
            int len = log(n)/log(3);
            
            if (ps[len]) return false;
            else ps[len] = 1;
            
            n -= pow(3, len);
        }
        
        return true;
    }
};
