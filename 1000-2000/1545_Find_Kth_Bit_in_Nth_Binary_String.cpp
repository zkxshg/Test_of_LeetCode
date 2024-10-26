// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/?envType=daily-question&envId=2024-10-19
// Recursion

class Solution {
public:
    char recur(int n, int k) {
        if (n == 1) return '0';

        int len = pow(2, n) - 1; 
        if (len == k * 2 - 1) return '1';
        else if (k <= len / 2) return recur(n - 1, k);
        else {
            if (recur(n - 1, len - k + 1) == '1') return '0';
            else return '1';
        }

        return 'err';
    }
    
    char findKthBit(int n, int k) {
        return recur(n, k);
    }
};
