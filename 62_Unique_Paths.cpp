// Combinatorics
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long multi = 1;
        for (int i = m; i < m + n - 1; i++) {
            multi *= i;
            multi /= (i - m + 1);
        }
        return multi;
    }
};
