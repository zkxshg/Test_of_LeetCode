// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/
// string

class Solution {
public:
    vector<string> cellsInRange(string s) {
        int c1 = s[0] - 'A', c2 = s[3] - 'A';
        int r1 = s[1] - '0', r2 = s[4] - '0';
        
        vector<string> res;
        for (int i = c1; i <= c2; i++) {
            for (int j = r1; j <= r2; j++) {
                string tem = ""; 
                tem += 'A' + i; tem += '0' + j;
                res.push_back(tem);
            }
        }
        
        return res;
    }
};
