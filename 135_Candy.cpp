// https://leetcode.com/problems/candy/
// sort + greedy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); 
        if (n == 1) return 1;
        
        vector<pair<int, int> > v2p;
        for (int i = 0; i < n; i++)
            v2p.push_back(make_pair(ratings[i], i));
        sort(v2p.begin(), v2p.end());
        
        vector<int> res(n);
        
        for (auto& p : v2p) {
            int val = p.first, pos = p.second;
            
            // int pre = (pos > 0 ? res[pos - 1] : 0);
            // int nex = (pos < n - 1 ? res[pos + 1] : 0);
            
            int cand = 1;
            if (pos > 0 && ratings[pos] > ratings[pos - 1] ) cand = max(cand, res[pos - 1] + 1);
            if (pos < n - 1 && ratings[pos] > ratings[pos + 1] ) cand = max(cand, res[pos + 1] + 1);
            
            res[pos] = cand;
        }
        
        int tres = 0;
        for (int i : res) tres += i;
        return tres;
    }
};
