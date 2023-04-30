// https://leetcode.com/problems/interleaving-string/
// DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        
        vector<pair<int, int>> cands; cands.push_back(make_pair(0, 0));
        
        for (int i = 0; i < n3; i++) {
           vector<pair<int, int>> tem;
            
            for (auto& p : cands) {
                if (p.first < n1 && s3[i] == s1[p.first]) {
                    pair<int, int> np = make_pair(p.first + 1, p.second);
                    
                    if (find(tem.begin(), tem.end(), np) == tem.end())
                        tem.push_back(np);
                }    
                
                if (p.second < n2 && s3[i] == s2[p.second]) {
                    pair<int, int> np = make_pair(p.first, p.second + 1);
                    
                    if (find(tem.begin(), tem.end(), np) == tem.end())
                        tem.push_back(np);
                }
            }
            
            if (tem.empty()) return false;
            //for (auto& p : tem) cout << p.first << ":" << p.second << ", "; cout << endl;
            cands = tem;
            
        }
        
        return true;
    }
};
