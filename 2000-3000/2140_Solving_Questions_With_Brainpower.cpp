// https://leetcode.com/problems/solving-questions-with-brainpower/
// DP

class Solution {
public:
    #define ll long long
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        vector<ll> scores(n);
        
        ll res = 0;
        for (int i = 0; i < n; i++) {
            ll p = questions[i][0], bp = questions[i][1];
            
            if (i > 0) scores[i] = max(scores[i], scores[i - 1]);
            
            ll score = scores[i] + p;
            
            res = max(res, score);
            
            if (i + bp < n - 1) scores[i + bp + 1] = max(scores[i + bp + 1], score);
        }
        // for (int s : scores) cout << s << ","; cout << endl;
        return res;
        
    }
};
