// Greedy
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int len = tokens.size(); if (len < 1) return 0;
        
        sort(tokens.begin(), tokens.end());
        if (P < tokens[0]) return 0;
        
        int tokNum = len, score = 0;
        int powT = 0, scoT = len - 1;
        while (powT <= scoT) {
            if (P >= tokens[powT]) {
                P -= tokens[powT];
                score++;
                powT++;
            }
            else {
                if (powT == scoT) return score;
                
                score--;
                P += tokens[scoT];
                scoT--;
            }
        } 
        return score;
    }
};
