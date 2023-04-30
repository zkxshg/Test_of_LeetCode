// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// bit manipulation
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int len = s.size(); if (len < k) return false;
        
        int kind = 0, knum = pow(2, k);
        unordered_map<int, int> fre;
        
        for (int i = 0; i <= len - k; i++) {
            int num = 0;
            for (int j = 0; j < k; j++) num += s[i + j] * pow(2, j);
            fre[num]++; 
            
            if (fre[num] == 1) kind++;
            if (kind == knum) return true;
        }
        return false;
    }
};
