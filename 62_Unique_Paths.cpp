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

// DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        int result = 0;
        result = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        return result;
    }
};
