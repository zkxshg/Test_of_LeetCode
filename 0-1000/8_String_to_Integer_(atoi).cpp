https://leetcode.com/problems/string-to-integer-atoi/
// string

class Solution {
public:
    #define ll long long
    ll neg_max = pow(2, 31);
    ll int_max = INT_MAX;
    
    int myAtoi(string s) {
        ll res = 0;
        bool neg = false;
        
        int n = s.size(), pos = 0;
        
        while (s[pos] == ' ') pos++;
        
        if (s[pos] == '+' || s[pos] == '-') {
            if (s[pos] == '-') neg = true;
            pos++;
        }
        
        while (s[pos] >= '0' && s[pos] <= '9') {
            res = res * 10 + (s[pos] - '0');
            
            if (neg) res = min(neg_max, res);
            else res = min(int_max, res);
            
            pos++;
        }
        
        if (neg) return -res;
        
        return res;
    }
};
