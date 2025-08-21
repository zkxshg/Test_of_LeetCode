// DP
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(); if (n < 3) return 0;
        
        vector<int> dif(n - 1);
        for (int i = 0; i < n - 1; i++) dif[i] = A[i + 1] - A[i];
        
        vector<int> num(n - 1);
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (dif[i] == dif[i - 1]) num[i] = num[i - 1] + 1;
            if (num[i] >= 1) res += num[i];
        }
        return res;
    }
};
