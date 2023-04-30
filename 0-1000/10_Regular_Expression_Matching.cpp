// https://leetcode.com/problems/regular-expression-matching/
// DP + Backtracking + Greedy
class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size(), lenp = p.size();
        if (lens == 0 && lenp == 0) return true;
        if (lenp == 0) return false;
        
        vector<int> backP;
        
        vector<int> pos(lenp, -2);
        
        int temp = 0, tems = 0;
        while (pos.back() != lens - 1) {
            if (tems >= lens) {
                // * = 0
                if (temp < lenp - 1 && p[temp + 1] == '*') {
                    pos[temp++] = tems - 1;
                    pos[temp++] = tems - 1;
                    continue;
                }
                return false;
            }
            
            if (temp < lenp && (p[temp] == '.' || p[temp] == s[tems])){
                pos[temp] = tems;
                temp++;
                if (temp < lenp && p[temp] == '*'){
                    // * = 0
                    backP.push_back(temp);
                    pos[temp] = -2;
                    temp++;
                    continue;
                }  
                tems++;
            }
            else if (temp < lenp - 1 && p[temp + 1] == '*') {
                // * = 0
                pos[temp++] = tems;
                pos[temp++] = -2;
            }
            else if (backP.size() > 0) {
                // Backtracking
                
                // * = 0 -> * = 1
                if (pos[backP.back()] < 0) {
                    temp = backP.back();
                    tems = pos[temp - 1];
                    pos[temp] = tems;
                    temp++;
                    tems++;
                    continue;
                }
                
                // Delete the Backtracking point
                if (p[backP.back() - 1] != '.' &&
                    p[backP.back() - 1] != s[pos[backP.back()] + 1]) {
                    backP.pop_back();
                    continue;
                }
                
                // * = i -> * = i + 1, i > 0
                temp = backP.back();
                tems = pos[temp];
                pos[temp] = tems + 1;
                temp++;
                tems += 2; 
            }
            else return false;
        }
        
        return true;
    }
};
