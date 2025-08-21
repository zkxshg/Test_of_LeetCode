// https://leetcode.com/problems/minimum-operations-to-make-array-equal/
// math
class Solution {
public:
    int minOperations(int n) {
        int res = 0, len = n / 2;
        for (int i = 0; i < len; i++) res += n - (2 * i + 1);
        return res;
    }
}; 
