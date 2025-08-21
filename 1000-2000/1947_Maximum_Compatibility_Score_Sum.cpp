// https://leetcode.com/problems/maximum-compatibility-score-sum/
// permutation

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students[0].size(), m = students.size();
        
//         int maskLen = 1 << n;
//         vector<int> cands;
        
//         for (int i = 0; i < maskLen; i++) {
//             int trans = 0;

//             bitset<32> bits(i);
//             for (int j = 0; j < n; j++) {
//                 if (bits[j]) trans += pow(10, j);
//             }

//             cands.push_back(trans);
//         }
        // for (int i : cands) cout << i << ","; cout << endl;
        
//         unordered_map<int, int> c2in; int ind = 0;
//         for (int c : cands) {
//             c2in[c] = ind; ind++;
//         }
        
//         vector<vector<int> > distM(maskLen, vector<int>(maskLen, 0));
//         for (int i = 0; i < maskLen; i++) {
//             for (int j = i + 1; i < maskLen; i++) {
//                 int dis = 0, x = cands[i], y = cands[j];
//                 while (x) {
//                     if (x % 10 == y % 10) dis++;
//                     x /= 10; y /= 10;
//                 }
//                 distM[c2in[cands[i]]][c2in[cands[j]]] = dis;
//                 distM[c2in[cands[j]]][c2in[cands[i]]] = dis;
//             }
//         }
        
        vector<int> P(m); for (int i = 0; i < m; i++) P[i] = i;
        
        int tnum = 1; for (int i = m; i > 1; i--) tnum *= i;
        
        int res = 0;
        for (int i = 0; i < tnum; i++) {
            int tr = 0;
            
            for (int j = 0; j < m; j++) {
                vector<int>& st = students[j];
                vector<int>& me = mentors[P[j]];
                
                for (int k = 0; k < n; k++)
                    if (st[k] == me[k])
                        tr++;
            }
            
            res = max(res, tr);
            next_permutation(P.begin(), P.end());
        }
        
        return res;
        
    }
};
