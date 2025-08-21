// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// hash table

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        
        unordered_map<int, int> win;
        unordered_map<int, int> fail;
        
        for (int i = 0; i < n; i++) {
            win[matches[i][0]]++; fail[matches[i][1]]++;
        }
        
        vector<vector<int>> res(2);
        
        for (auto& p : win) {
            if (!fail[p.first]) {
                res[0].push_back(p.first); fail[p.first] = -1;
            }
            else if (fail[p.first] == 1) {
                res[1].push_back(p.first); fail[p.first] = -1;
            }
        }
        
        for (auto& p : fail) {
            if (p.second == 1) res[1].push_back(p.first);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};
