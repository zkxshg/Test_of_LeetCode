// array
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2) return n; 
        
        vector<int> gi(n + 1);
        gi[0] = 0; gi[1] = 1; 
        
        int res = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) gi[i] = gi[i/2];
            else gi[i] = gi[(i - 1) / 2] + gi[(i - 1) / 2 + 1];
            
            res = max(res, gi[i]);
        }
        
        return res; 
    }
};
