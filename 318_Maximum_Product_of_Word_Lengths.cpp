// https://leetcode.com/problems/maximum-product-of-word-lengths/
// bit maniputation

class Solution {
public:
    int maxProduct(vector<string>& words) {
        // for (char c = 'a'; c <= 'z'; c++) {
        //     bitset<4> b(c - 'a');
        //     cout << b << endl;
        // }
        
        int n = words.size();
        vector<int> mask(n);
        
        for (int i = 0; i < n; i++) {
            string& w = words[i];
            for (auto& c : w) mask[i] |= (1 << (c - 'a'));
        }
        
        int res = 0;
        for (int i = 0; i < n - 1; i++) 
            for (int j = i + 1; j < n; j++) 
                if (!(mask[i] & mask[j])) 
                    res = max(res, int(words[i].size() * words[j].size()));
        
        return res;     
    }
};
