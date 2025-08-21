// stack: O(n)
class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.size(); if (n <= 2) return 1;
        
        int sco = 0;
        vector<int> W;
        stack<char> par;
        
        for (char ch : S) {
            if (ch == '(') {
                par.push(ch);
                W.push_back(1);
            }
            else {
                int nex = W.back();              
                par.pop(); 
                W.pop_back();
                
                if (par.empty()) sco += nex;
                else {
                    if (W.back() == 1) W.back() = nex * 2;
                    else W.back() += nex * 2;
                }
            }
        }
        
        return sco;
        
    }
};
