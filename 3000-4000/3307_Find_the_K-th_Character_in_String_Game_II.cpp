// 3307. Find the K-th Character in String Game II
// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/
// Lang: C++
// Date: 2025-08-21 21:04:55.160 UTC

class Solution {
public:
    #define ll long long

    char recur(ll k, vector<int>& oper) {
        if (k == 1) return 'a';

        int log2k = log2(k);
        if (pow(2, log2k) < k) log2k++;

        // cout << k << ":" << log2k << endl;

        char res = 'a';

        if (oper[log2k - 1] == 0) res = recur(k - pow(2, log2k - 1), oper);
        else res = recur(k - pow(2, log2k - 1), oper) + 1;

        if (res > 'z') res = 'a';
        
        return res;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1) return 'a';

        int log2k = log2(k);
        if (pow(2, log2k) < k) log2k++;

        return recur(k, operations);
    }
};
