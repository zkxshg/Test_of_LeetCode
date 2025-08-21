// https://leetcode.com/problems/shortest-distance-to-a-character/
// two pointers

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int pre = -1001, suf = -1, n = s.size();
        
        vector<int> carr;
        for (int i = 0; i < n; i++) 
            if (s[i] == c) carr.push_back(i);
        
        int cpos = 0, cn = carr.size();;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (s[i] != c) {
                while (cpos < cn - 1 && i > carr[cpos]) cpos++;
                //cout << carr[cpos] << "-" << i << endl;
                res[i] = abs(i - carr[cpos]);
                if (cpos > 0) res[i] = min(res[i], abs(i - carr[cpos - 1]));
            } 
        }
        
        return res;
    }
};
