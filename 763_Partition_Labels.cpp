// two pointers -> merge intervals
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<int> result;
        if (len < 2) return result;
        
        unordered_map<char, int> lastPos;
        for (int i = 0; i < len; i++) lastPos[S[i]] = i;
        
        string temS = "";
        temS += S[0];
        
        int deltaL = 1, temPos = 0, nexPos = lastPos[S[0]];
        while (temPos < len) {
            
            while (temPos != nexPos) {
                int nex = nexPos;
                for (int i = temPos + 1; i < nexPos; i++) {
                    if (lastPos[S[i]] > nex) nex = lastPos[S[i]];
                }
                temPos = nexPos;
                nexPos = nex;
            }
            
            temPos++;
            result.push_back(temPos);
            if (temPos < len) nexPos = lastPos[S[temPos]];
        }
        
        for (int i = result.size() - 1; i > 0; i--) result[i] -= result[i - 1];
        return result;
    }
};
