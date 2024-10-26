// https://leetcode.com/problems/parsing-a-boolean-expression/?envType=daily-question&envId=2024-10-20
// Recursion + Stack

class Solution {
public:
    unordered_map<int, int> RBs;
    unordered_map<int, vector<int>> commas;

    bool recur(string& expre, int l, int r) {
        //cout << l << ":" << r << " = " << expre.substr(l, r - l + 1) << endl;

        if (l >= r) {
            if (expre[l] == 't') return true;
            else return false;
        }

        int lb = l + 1;
        int rb = RBs[lb];

        //cout << lb << "~" << rb << endl;
        
        if (expre[l] == '!') return (!(recur(expre, lb + 1, rb - 1)));

        vector<int>& cms = commas[lb];
        if (cms.empty()) return recur(expre, lb + 1, rb - 1);

        if (expre[l] == '|') {
            bool res = recur(expre, lb + 1, cms[0] - 1);

            for (int i = 1; i < cms.size(); i++) 
                res |= recur(expre, cms[i - 1] + 1, cms[i] - 1);

            res |= recur(expre, cms.back() + 1, rb - 1);

            return res;
        }

        if (expre[l] == '&') {
            bool res = recur(expre, lb + 1, cms[0] - 1);

            for (int i = 1; i < cms.size(); i++) 
                res &= recur(expre, cms[i - 1] + 1, cms[i] - 1);

            res &= recur(expre, cms.back() + 1, rb - 1);

            return res;
        }

        return false;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        RBs.clear(); commas.clear();

        vector<int> st;
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == '(') {
                st.push_back(i);
            }
            else if (c == ')') {
                RBs[st.back()] = i;
                st.pop_back();
            }
            else if (c == ',') {
                commas[st.back()].push_back(i);
            }
        }

        return recur(expression, 0, n - 1);   
    }
};
