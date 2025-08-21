// https://leetcode.com/problems/expression-add-operators/
// bit mask

class Solution {
public:
    #define ll long long
    
    ll calculate(string& s, string& op) {
        vector<ll> st; st.push_back(s[0] - '0');
        vector<int> signs; signs.push_back(1);
        
        ll res = 0, n = s.size();
        
        for (int i = 0; i < n - 1; i++) {
            char c = op[i];
            
            if (c == '+' || c == '-') {
                // deal with *
                while (st.size() > 1) {
                    int v = st.back(), sign = signs.back();
                    st.pop_back(); signs.pop_back();
                    
                    st.back() *= v;  signs.back() = (signs.back() & sign);
                }
                
                // add
                if (signs.back()) res += st.back();
                else res -= st.back();
                
                // initial 
                st.back() = s[i + 1] - '0';
                if (c == '+') signs.back() = 1;
                else signs.back() = 0;
            }
            else if (c == '_') st.back() = st.back() * 10 + (s[i + 1] - '0');
            else {
                st.push_back(s[i + 1] - '0');
                signs.push_back(1);
            }
        }
        
        // deal with tail
        while (st.size() > 1) {
            int v = st.back(), sign = signs.back();
            st.pop_back(); signs.pop_back();

            st.back() *= v;  signs.back() = (signs.back() & sign);
        }
        
        if (signs.back()) res += st.back();
        else res -= st.back();
        
        return res;
    }
    
    string plus(string& s, string& op) {
        int n = s.size();
        string res = ""; res += s[0];
        for (int i = 0; i < n - 1; i++) {
            if (op[i] != '_') res += op[i]; 
            res += s[i + 1];
        }
        return res;
    }
        
    vector<string> addOperators(string num, int target) {
        int n = num.size(); 
        
        if (n == 1) {
            if (num[0] - '0' == target) return {num};
            else return {};
        }
        
        vector<string> res;
        
        // Bit mask
        int len = n - 1;
        int maskLen = 1 << len;
        
        for (int i = 0; i < maskLen; i++) {
            for (int j = 0; j < maskLen; j++) {
                string op = "";
                
                bitset<32> bi(i); bitset<32> bj(j);
                
                bool leadZero = false;
                for (int k = 0; k < len; k++) {
                    if (bi[k] && bj[k]) op += '+';
                    else if (bi[k] && !bj[k]) op += '-';
                    else if (!bi[k] && bj[k]) {
                        op += '_';
                        
                        if (num[k] == '0') {
                            if (k == 0) {
                                leadZero = true;
                                break;
                            }
                            
                            for (int k2 = k - 1; k2 >= 0; k2--) {
                                if (op[k2] != '_') {
                                    if (num[k2 + 1] == '0') leadZero = true;
                                    break;
                                }
                            }
                        } 
                    }
                    else if (!bi[k] && !bj[k]) op += '*';
                }
                
                if (leadZero) continue;
                
                if (calculate(num, op) == target) res.push_back(plus(num, op));
                // if (calculate(num, op) == target) res.push_back(op);
            }
        }
        
        return res;
        
    }
};
