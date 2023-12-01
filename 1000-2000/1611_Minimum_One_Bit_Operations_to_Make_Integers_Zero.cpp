// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Bit manipulation

class Solution {
public:
    int dfs(int n) {
        if (n == 0) return 0;

        int onePos = 32 - (__builtin_clz(n));
        int res = pow(2, onePos) - 1; 

        int mask = ~(1 << onePos - 1); 
        n &= mask;

        return res - dfs(n);
    }

    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        return dfs(n);
    }

};
