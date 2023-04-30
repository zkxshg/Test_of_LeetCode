// https://leetcode.com/problems/k-th-symbol-in-grammar/
// Recursion

class Solution {
public:
    int find(int n, int k) {
        if (n == 1) return 0;
        
        int preK = (k / 2) + (k % 2);
        
        if (k % 2) return find(n - 1, preK);
        else return 1 - find(n - 1, preK);
    }
    
    int kthGrammar(int n, int k) {
        return find(n, k);
    }
};
