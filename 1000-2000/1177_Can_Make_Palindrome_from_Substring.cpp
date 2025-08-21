// https://leetcode.com/problems/can-make-palindrome-from-substring/
// prefix sum + successor table / DP

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<vector<int> > succ(26, vector<int>(n));
        succ[s[0] - 'a'][0] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) succ[j][i] = succ[j][i - 1];
            succ[s[i] - 'a'][i] = succ[s[i] - 'a'][i - 1] + 1;
        }
        
        vector<bool> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            
            int oddNum = 0;
            for (int i = 0; i < 26; i++) {
                int lv = (l > 0) ? succ[i][l - 1] : 0;
                if ((succ[i][r] - lv) % 2) oddNum++;        
            }
            
            if (oddNum - k * 2 <= 1) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};
