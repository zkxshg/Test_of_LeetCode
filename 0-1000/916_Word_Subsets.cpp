// https://leetcode.com/problems/word-subsets/
// hahs table

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1 = words1.size(), n2 = words2.size();
        
        vector<int> barr(26);
        for (auto& str : words2) {
            vector<int> tem(26);
            for (char c : str) tem[c - 'a']++;
            for (int i = 0; i < 26; i++) barr[i] = max(barr[i], tem[i]);
        }

        vector<string> res;
        for (auto& str : words1) {
            vector<int> aarr(266);
            for (char c : str) aarr[c - 'a']++;
            
            bool subs = true;
            for (int i = 0; i < 26; i++) {
                if (aarr[i] < barr[i]) {
                    subs = false; break;
                }
            }
                
            if (subs) res.push_back(str);
        }
        
        return res;
    }
};
