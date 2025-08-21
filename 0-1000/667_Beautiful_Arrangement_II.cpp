// https://leetcode.com/problems/beautiful-arrangement-ii/
// greedy
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i) A[i] = i + 1;
        
        if (k == 1) return A;
        
        vector<int> res;
        for (int i = 0; i < (k + 1) / 2; i++) {
            res.push_back(i + 1); res.push_back(k + 1 - i);
        }
        
        if (k % 2 == 0) res.push_back(k / 2 + 1);
        
        for (int i = k + 2; i <= n; i++) res.push_back(i);
        
        return res;
    }
};
