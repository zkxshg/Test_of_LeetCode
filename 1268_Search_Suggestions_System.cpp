// https://leetcode.com/problems/search-suggestions-system/
// Trie / Hash table

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, vector<string>> dict;
        
        for (auto& p : products) {
            int n = p.size();
            
            for (int i = 0; i < n; i++) {
                string prefix = p.substr(0, i + 1);
                dict[prefix].push_back(p);
            }
        }
        
        vector<vector<string>> res; string tem = "";
        for (char c : searchWord) {
            tem += c;
            
            vector<string> resi = dict[tem];
            
            sort(resi.begin(), resi.end());
            
            if (resi.size() > 3) 
                while (resi.size() > 3) 
                    resi.pop_back();

            res.push_back(resi);
        }
        
        return res;
    }
};
