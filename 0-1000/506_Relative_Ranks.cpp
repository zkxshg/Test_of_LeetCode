// https://leetcode.com/problems/relative-ranks/
// sorting

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<string> rank(n);
        
        vector<pair<int, int> > S;
        for (int i = 0; i < n; i++) S.push_back({score[i], i});
        sort(S.begin(), S.end(), greater<pair<int,int> >());
        
        if (n > 0) rank[S[0].second] = "Gold Medal";
        if (n > 1) rank[S[1].second] = "Silver Medal";
        if (n > 2) rank[S[2].second] = "Bronze Medal";
        
        for (int i = 3; i < n; i++) rank[S[i].second] = to_string(i + 1);
        
        return rank;
    }
};
