// https://leetcode.com/problems/basic-calculator/
// stack + FSM

class Solution {
public:
    #define ll long long
    
    int calculate(string s) {
        int res = 0;
        
        if (s[0] != '(') s = "(" + s + ")";
        
        vector<int> P;
        vector<ll> S; S.push_back(0);
        vector<int> N;
        
        for (char c : s) {
            
            if (c >= '0' && c <= '9') S.back() = S.back() * 10 + (c - '0');
            else if (c == '+' || c == '-') {
                if (!N.empty() && N.size() >= P.size()) {
                    int tail = S.back(); S.pop_back();
                    
                    if (N.back() > 0) S.back() += tail;
                    else S.back() -= tail;
                    
                    N.pop_back();
                }
                
                if (c == '+') N.push_back(1);
                else N.push_back(-1);
                
                S.push_back(0);
                
            }
            else if (c == '(' || c == ')') {
                
                if (c == ')') {
                    P.pop_back();
                    
                    if (!N.empty() && N.size() > P.size()) {
                        int tail = S.back(); S.pop_back();

                        if (N.back() > 0) S.back() += tail;
                        else S.back() -= tail;

                        N.pop_back();
                    }
                    
                }
                else {
                    P.push_back(1);
                    // if (!N.empty()) S.push_back(0);
                }
            }
            // cout << "c = " << c << "->" ;
            // for (int i : S) cout << i << ","; cout << ";";
            // for (int i : N) cout << i << ","; cout << endl;
        }
        
        if (!N.empty()) {
            int tail = S.back(); S.pop_back();
            if (N.back() > 0) S.back() += tail;
            else S.back() -= tail;
            N.pop_back();
        }
        
        return S[0];
    }
};
