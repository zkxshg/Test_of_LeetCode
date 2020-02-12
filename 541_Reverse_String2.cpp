// case 1: len <= k; case 2 : len <= 2*k; case 3 : len > 2*k
#include <algorithm>
class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        string s2;
        if (k >= length)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        else if (2 * k >= length)
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s_1 = s_left + s.substr(k, length);
            return s_1;
        }
        else
        {
            string s_left = s.substr(0, k);
            reverse(s_left.begin(), s_left.end());
            string s2 = s_left + s.substr(k, k);
            s2 += reverseStr(s.substr(2*k, length), k);
            return s2;
        }      
    } 
};
