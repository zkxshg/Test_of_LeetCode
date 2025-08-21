// https://leetcode.com/problems/matchsticks-to-square/
// bitmask
class Solution {
public:
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(); if (n < 4) return false;
        
        int sum = 0; for (int i : matchsticks) sum += i;
        if (sum % 4) return false;
        
        int line = sum / 4, maskLen = 1 << n;
        
        vector<int> Ncand; // set that sum equal to sum / 2
        for (int i = 0; i < maskLen; i++) {
            bitset<32> bi(i);
            
            int l12 = 0;
            for (int k = 0; k < n; k++) 
                if (bi[k]) {
                    l12 += matchsticks[k];
                    if (l12 > line * 2) break;
                }
                    
            if (l12 == line * 2) Ncand.push_back(i);
        }
        
        int m = Ncand.size();
        for (int i = 0; i < m; i++) {
            bitset<32> bi(Ncand[i]);
            
            
            for (int j = 0; j < m; j++) {
                int s = 0;
                bitset<32> bj(Ncand[j]);
                
                for (int k = 0; k < n; k++) {
                    if (bi[k] && bj[k]) {
                        s += matchsticks[k];
                        if (s > line) break;
                    }
                }
                
                if (s == line) return true;
            }
            
        }
        
        return false;
        
    }
};

// backtracking

class Solution {
public:
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(); if (n < 4) return false;
        
        int sum = 0; for (int i : matchsticks) sum += i;
        if (sum % 4) return false;
        
        int line = sum / 4, maskLen = 1 << n;
        for (int i = 0; i < maskLen; i++) {
            bitset<32> bi(i);
            
            int l12 = 0;
            for (int k = 0; k < n; k++) 
                if (bi[k])
                    l12 += matchsticks[k];
            
            if (l12 != line * 2) continue;
            
            for (int j = 0; j < maskLen; j++) {
                bitset<32> bj(j);
                
                int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
                for (int k = 0; k < n; k++) {
                    if (bi[k] && bj[k]) l1 += matchsticks[k];
                    else if (bi[k] && !bj[k]) l2 += matchsticks[k];
                    else if (!bi[k] && bj[k]) l3 += matchsticks[k];
                    else l4 += matchsticks[k];
                    
                    if (l1 > line || l2 > line || l3 > line || l4 > line) break;
                }
                //cout << l1 << ":" << l2 << ":" << l3 << ":" << l4 << endl;
                if (l1 == l2 && l3 == l4 && l1 == l3) return true; 
            }
            cout << i << endl;
        }
        
        return false;
        
    }
};
