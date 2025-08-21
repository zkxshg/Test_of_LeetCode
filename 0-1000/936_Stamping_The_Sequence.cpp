// https://leetcode.com/problems/stamping-the-sequence/
// greedy
class Solution {
public:
    vector<int> movesToStamp(string S, string T) {
        if (S == T) return {0};
        int slen = S.size(), tlen = T.size() - slen + 1, i, j;
        
        vector<int> ans;
        bool tdiff = true, sdiff = false;
        
        while (tdiff) {
            tdiff = false;
            for (i = 0; i < tlen; i++) {
                
                sdiff = false;
                for (j = 0; j < slen; j++) {
                    if (T[i+j] == '-') continue;
                    else if (T[i+j] != S[j]) break;
                    else sdiff = true;
                }
                    
                if (j == slen && sdiff) {
                    tdiff = true;
                    for (j = i; j < slen + i; j++) T[j] = '-';    
                    ans.push_back(i);
                }
            }
        }
            
        for (i = 0; i < T.size(); i++) if (T[i] != '-') return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// DP
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int slen = stamp.size(), tlen = target.size();
        
        if (target[0] != stamp[0] || target[tlen - 1] != stamp[slen - 1]) return {};
        
        if (slen == tlen) {
            if (stamp == target) return {0};
            else return {};
        }
        
        unordered_map<char, int> preT;
        for (int i = 0; i < slen; i++) {
            if (!preT[stamp[i]]) preT[stamp[i]] = i + 1;
        }
        
        vector<int> res;
        
        bool dif = true;
        while (dif) {
            int i = 0; dif = false;
            
            while (i < tlen) {
                if (target[i] == '-') i++;
                else if (preT[target[i]]) {
      
                    bool getS = false; int stp = -1;
                    
                    if (i > 0 && target[i - 1] != '-' && preT[target[i]] > 1) {
                        i++; continue;
                    }
                    
                    for (int j2 = preT[target[i]] - 1; j2 < slen; j2++) {
                        if (j2 > i) break;
                        
                        if (target[i] != stamp[j2]) continue;
                        
                        bool sameS = true; 
                        int cou = 0;
                        
                        for (int j = j2 + 1; j < slen; j++) {
                            cou++;
                            if (i + cou >= tlen) {
                                sameS = false; break;
                            }
                            
                            if (target[i + cou] == '-') continue;  
                            
                            if (target[i + cou] != stamp[j]) {
                                sameS = false; break;
                            }
                        }
     
                        if (sameS) {
                            getS = true; stp = j2; break;
                        }
                        
                    }
 
                    if (getS) {
                        int st = i - stp;
                        res.push_back(st);
                        for (int k = st; k < st + slen; k++) target[k] = '-';
                        
                        i += slen;
                        dif = true;
                    }
                    else i++;
                }
                else i++; 

            }
        }
            
        for (char ch : target) if (ch != '-') return {};
        
        reverse(res.begin(), res.end());
        return res;  
    }
};
