// https://leetcode.com/problems/couples-holding-hands/
// union-find

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size() / 2;
        if (n == 1) return 0;
        
        unordered_map<int, int> ntr;
        for (int i = 0; i < n; i++) {
            
            int a = row[i * 2], b = row[i * 2 + 1];
            
            // couples
            if (abs(a - b) == 1 && !(min(a, b) % 2)) {
                ntr[a] = -1; ntr[b] = -1; continue;
            }
            else {
                // ntr
                ntr[a] = b; ntr[b] = a;
            }
        }
        
        for (int i = 0; i < 2 * n; i += 2) {
            if (ntr[i] > 0) {
                int tem = ntr[i]; ntr[i] = -1; 
                
                while (tem != i + 1) {
                    int s = tem, s2 = -1;
                    
                    if (tem % 2) s2 = tem - 1;
                    else s2 = tem + 1;
                    
                    tem = ntr[s2];
                    
                    ntr[s] = -1; ntr[s2] = -1;
                    res++;
                }
                ntr[i] = -1; ntr[i + 1] = -1;
            }
        }
        
        return res;
        
    }
};
