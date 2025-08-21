// https://leetcode.com/problems/count-numbers-with-unique-digits/
// DP / math

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> ans(9); ans[0] = 1;
        for (int i = 1; i <= n; i++) ans[i] = ans[i - 1] * (10 - i);
        
        vector<int> sum(9); sum[0] = 1; 
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + 9 * ans[i - 1];
        
        return sum[n];
    }
};
