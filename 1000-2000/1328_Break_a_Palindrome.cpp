// https://leetcode.com/problems/break-a-palindrome/ 
// Greedy

class Solution {
public:
    #define P palindrome
    string breakPalindrome(string palindrome) {
        int n = P.size(); if (n == 1) return "";
        
        for (int i = 0; i < n / 2; i++) {
            if (P[i] != 'a') {
                P[i] = 'a'; return P;
            }
        }
        
        P.back() = 'b'; 
        return P;
    }
};
