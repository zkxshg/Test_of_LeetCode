// math
class Solution {
public:
    int reachNumber(int target) {
        if (target == 0) return 0;
        if (target == 1 || target == -1) return 1; 
        target = abs(target);
        
        int step = 1;
        while (target >= step) {
            target -= step;
            if (target == 0) return step;
            step++;
        }
        
        if ((step - target) % 2) step += 2 - (1- step % 2);
        return step;
    }
};
