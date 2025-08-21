// binary search
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        if (num == 4) return true;
        
        bool perfect = false;
        int start = 2;
        int ender = num;
        int aim = 0;
        
        while(start < ender){
            int k = start + (ender - start) / 2;
            if (k == start || k == ender) break;
            int subs = num/k;
            if (subs == k) {
                aim = k;
                break;
            }
            else if (subs < k) ender = k;
            else start = k;
        }
        if (aim != 0 && num % aim == 0) perfect =  true;
        return perfect;
    }
};
