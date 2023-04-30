// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// bit maniputation + hash map

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int m = words.size(), n = puzzles.size();
        
        vector<int> wi(m);
        for (int i = 0; i < m; i++) 
            for (char c : words[i]) wi[i] |= (1 << (c - 'a'));
        
        unordered_map<int, int> fre;
        for (int i = 0; i < m; i++) {
            int wi = 0;
            for (char c : words[i]) wi |= (1 << (c - 'a'));
            fre[wi]++;
        }
        
        vector<int> pi(n);
        for (int i = 0; i < n; i++) 
            for (char c : puzzles[i]) pi[i] |= (1 << (c - 'a'));
        
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int fir = (1 << (puzzles[i][0] - 'a'));
            
            int subs = pi[i];
            while (subs) {
                if (fir & subs) res[i] += fre[subs];
                subs = (subs - 1) & pi[i];
            }
        }
        
        return res;
    }
};
