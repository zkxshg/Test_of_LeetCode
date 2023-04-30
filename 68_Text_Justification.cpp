// https://leetcode.com/problems/text-justification/
// Useless simulation

class Solution {
public:
    
    #define mw maxWidth
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<int> lens (n); for (int i = 0; i < n; i++) lens[i] = words[i].size();
        
        vector<string> res;
        
        int pos = 0;
        while (pos < n) {
            // Greedy insert
            int l = 0, nex = pos;
            
            while (l < mw - (nex - pos) && nex < n) {
                if (l + lens[nex] + (nex - pos) > mw) break;
                l += lens[nex]; nex++; 
                // cout << l << endl;
            }
            
            // share the spaces
            int spnum = mw - l;  // total spaces number
            int sp_per = 0, num_plus = 0; 
            
            if (nex - 1 > pos) {
                sp_per = spnum / (nex - pos - 1); // each space number
                num_plus = spnum % (nex - pos - 1); // number of plus 1
            }
            
            // Gener the string
            string str;
            for (int i = 0; i < num_plus; i++) {
                str += words[pos + i]; 
                for (int j = 0; j <= sp_per; j++) str += ' ';
            }
            
            for (int i = pos + num_plus; i < nex - 1; i++) {
                str += words[i]; 
                for (int j = 0; j < sp_per; j++) str += ' ';
            }
            
            str += words[nex - 1];
            
            // Last Line
            if (nex >= n) {
                str = ""; for (int i = pos; i < nex - 1; i++) {str += words[i]; str += ' ';}
                str += words.back();
            }

            // fill the last string
            if (str.size() < mw)
                while (str.size() < mw) str += ' ';
            
            // cout << str.size() << "= [" << pos << ":" << nex << "]" << endl;
            res.push_back(str);
            
            pos = nex;
        }
        
        return res;
    }
};
