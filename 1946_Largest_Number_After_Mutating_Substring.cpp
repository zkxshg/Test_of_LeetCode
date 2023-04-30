// https://leetcode.com/problems/largest-number-after-mutating-substring/
// array

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        
        int st = 0;
        while (st < n) {
            if (change[num[st] - '0'] > num[st] - '0') break;
            st++;
        }
        
        if (st >= n) return num;
        
        while (st < n) {
            if (change[num[st] - '0'] < num[st] - '0') break;
            else num[st] = change[num[st] - '0'] + '0';
            
            st++;
        }
        
        return num;
    }
};
