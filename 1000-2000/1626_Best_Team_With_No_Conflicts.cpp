// https://leetcode.com/problems/best-team-with-no-conflicts/
// DP

class Solution {
public:
    #define S scores
    #define A ages
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = S.size(); if (n == 1) return S[0];
        
        vector<pair<int, int> > team;
        for (int i = 0; i < n; i++) team.push_back(make_pair(A[i], S[i]));
        
        sort(team.begin(), team.end());
        
        // for (auto& p : team) cout << p.first << ":" << p.second << endl;
        
        vector<int> res(n); res[0] = team[0].second;
        
        int mr = 0;
        for (int i = 1; i < n; i++) {
            int si = team[i].second;
            int tem = si;
            
            for (int j = 0; j < i; j++) 
                if (team[i].first == team[j].first || team[j].second <= si)
                    tem = max(tem, si + res[j]);
            
            res[i] = tem;
            
            mr = max(mr, tem);
        }
        
        return mr;
    }
};
