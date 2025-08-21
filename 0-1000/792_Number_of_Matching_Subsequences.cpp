// https://leetcode.com/problems/number-of-matching-subsequences/
// string + successor table

class Solution {
public:
    vector<vector<int> > succTable(string A, int m, int alpha) {
        int len = m;
        vector<vector<int> > succesT(alpha, vector<int>(len + 1, len * 10));
  
        for (int i = len - 1; i >= 0; i--) {
            for (int j2 = 0; j2 < alpha; j2++) {
                char j = 'a' + j2; 
                if (A[i] == j) succesT[j2][i] = i + 1; 
                else succesT[j2][i] = succesT[j2][i + 1];
            }
        }
  
        return succesT;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int m = s.size();
        
        vector<vector<int> > st = succTable(s, m, 26);
        
        int res = 0;
        
        for (string word : words) {
            int pos = 0;
            
            bool get = true;
            for (char ws : word) {
                int w = ws - 'a';
                if (pos > m || st[w][pos] > m) {
                    get = false; break;
                }
                else pos = st[w][pos];
            }
            
            if (get) res++;
        }
        
        return res;
    }
};
