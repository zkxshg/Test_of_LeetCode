// 3304. Find the K-th Character in String Game I
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
// Lang: C++
// Date: 2025-08-21 21:05:01.574 UTC

class Solution {
public:
    char kthCharacter(int k) {
        if (k == 1) return 'a';

        int log2k = log2(k);
        if (pow(2, log2k) < k) log2k++;

        // cout << log2k << endl;

        return kthCharacter(k - pow(2, log2k - 1)) + 1; 
    }
};
