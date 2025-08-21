// https://leetcode.com/problems/accounts-merge/
// hash map + union find

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        unordered_map<string, int> user;
        vector<vector<string>> res;
        
        int n1 = accounts[0].size(); res.push_back({accounts[0][0]});
        for (int i = 1; i < n1; i++) {
            if (!user[accounts[0][i]]) {
                user[accounts[0][i]] = 1; res[0].push_back(accounts[0][i]);
            }
        }
        
        bool conf = false;
        
        for (int i = 1; i < n; i++) {
            vector<string>& acc = accounts[i];
            int tn = acc.size();
            
            bool ifSm = false; int smInd = 0;
            for (int j = 1; j < tn; j++) {
                if (user[acc[j]]) {
                    if (ifSm && user[acc[j]] != smInd) conf = true;
                    ifSm = true; smInd = user[acc[j]];
                }
            }
            
            if (ifSm) {
                for (int j = 1; j < tn; j++) {
                    if (user[acc[j]] != smInd) {
                        user[acc[j]] = smInd;
                        res[smInd - 1].push_back(acc[j]);
                    }
                }
            }
            else {
                int newInd = res.size() + 1;
                res.push_back({acc[0]});
                for (int j = 1; j < tn; j++) {
                    if (!user[acc[j]]) {
                        user[acc[j]] = newInd; res[newInd - 1].push_back(acc[j]);
                    }
                }
            }
        }
        
        for (auto& vs : res) sort(vs.begin() + 1, vs.end());
        
        if (!conf) return res;
        // cout << conf << endl;
        return accountsMerge(res);
    }
};
