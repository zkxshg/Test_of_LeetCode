// https://leetcode.com/problems/find-array-given-subset-sums/submissions/
// divide and conquer

class Solution {
public:
    static bool cmp(int a, int b) {
        if (abs(a) == abs(b)) return (a > 0) ? true : false;
        return abs(a) < abs(b);
    }
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        int m = sums.size();
        
        unordered_map<int, int> dict;
        for (int i : sums) dict[i]++;
        
        sort(sums.begin(), sums.end());

        unordered_map<int, int> possi;
        unordered_map<int, int> noPossi;
        
        // Pre find the possible ai
        for (int i = 0; i < m; i++) {
            int k = sums[i];
            
            if (possi[k]) {
                possi[k]++; continue;
            }
            
            unordered_map<int, int> tem = dict;

            bool ai = true;
            // Check if k is ai 
            for (int j = 0; j < m; j++) {
                int x = sums[j]; 

                if (!tem[x]) continue;
                else {
                    tem[x]--;
                    
                    if (k >= 0) {
                        if (tem[x + k]) tem[x + k]--; 
                        else {ai = false; break;}
                    }
                    else { // k < 0
                        if (tem[x - k]) tem[x - k]--;
                        else {ai = false; break;}
                    } 
                }
            }

            if (ai) possi[k]++;
            else noPossi[k]++;
        }  
        
        vector<int> res; int sum = 0;
        vector<int> temS = sums;
        
        // Divide and conquer
        while (temS.size() > 1) {
            m = temS.size(); int aimK = temS[0]; // cout << m << endl;
            
            // vector<int> cand = temS; sort(cand.begin(), cand.end(), cmp);
            
            unordered_map<int, int> temD; queue<int> Q;
            for (int i : temS) {
                temD[i]++; Q.push(i);
            }
            
            // Find ai
            for (int i = 0; i < m; i++) {
                int k = temS[i];

                if (noPossi[k]) continue;
                if (i > 0 && k == temS[i - 1]) continue;
                
                unordered_map<int, int> tem = temD;
                queue<int> q = Q;
                
                bool ai = true;
                // Check if k is ai
                while (!q.empty()) {
                    int x = q.front(); q.pop();
                    
                    if (!tem[x]) continue;
                    else {
                        tem[x]--;

                        if (k >= 0) {
                            if (tem[x + k]) tem[x + k]--; 
                            else {
                                ai = false; break;
                            }
                        }
                        else { // k < 0
                            if (tem[x - k]) tem[x - k]--;
                            else {
                                ai = false; break;
                            }
                        }
                    }
                }
                
                // If k is ai
                if (ai) {
                    aimK = k;
                    res.push_back(k); // conquer
                    break;
                }
            }
            
            // divide vector temS
            vector<int> leftP;
            unordered_map<int, int> tem = temD;
            
            int k = aimK;
            for (int j = 0; j < m; j++) {
                int x = temS[j];
                if (!tem[x]) continue;
                
                tem[x]--;
                if (k >= 0) {
                    leftP.push_back(x); tem[x + k]--; 
                }
                else { // k < 0
                    leftP.push_back(x - k); tem[x - k]--; 
                } 
            }
            
            temS = leftP; 
        } 
        
        return res;
        
    }
};
