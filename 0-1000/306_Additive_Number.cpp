// https://leetcode.com/problems/additive-number/
// BackTracking

class Solution {
public:
    #define ll long long
    vector<vector<ll> > preCal;
    
    string seq;
    
    ll s2i(int st, int en) {
        ll res = 0;
        for (int i = st; i <= en; i++) res = res * 10 + (seq[i] - '0');
        return res;
    }
    
    bool ifAdd(ll pre, int pos) {
        int n = seq.size();
        
        for (int i = pos; i < min(n, pos + 18); i++) {
            if (seq[pos] == '0' && i > pos) break; 
            
            ll tem = preCal[pos][i]; if (tem < 0) break;
            
            for (int j = i + 1; j < min(n, i + 19); j++) {
                if (seq[i + 1] == '0' && j > i + 1) break;
                
                ll nex = preCal[i + 1][j]; if (nex < 0) break;
            
                  
                
                if (pre + tem == nex) {
                   // cout << "pre = " << pre << ", tem[" << pos << "," << i 
                   // << "]=" << tem << ", nex[" << i + 1 << "," << j << "]=" << nex << endl;
                    
                    if (j == n - 1) return true;
                    else if (ifAdd(tem, i + 1)) return true;
                } 
            }
        }
        
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        int n = num.size(); if (n < 3) return false;
        
        seq = num;
        
        preCal.resize(n, vector<ll>(n, -1));
        for (int i = 0; i < n; i++) 
            for (int j = i; j < min(n, i + 18); j++)
                preCal[i][j] = s2i(i, j);
        
        //for (int i = 0; i < n; i++) {
        //    for (int j = 0; j < n; j++) cout << preCal[i][j] << ",";
        //    cout << endl;
        //} cout << endl;
        
        for (int i = 0; i < n / 2; i++) {
            if (num[0] == '0' && i > 0) break;
            
            ll pre = preCal[0][i]; // cout << "i" << ": " << pre << endl;
            
            if (ifAdd(pre, i + 1)) return true;
        }
        
        return false;
    }
};
