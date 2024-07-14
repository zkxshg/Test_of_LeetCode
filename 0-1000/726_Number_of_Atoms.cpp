// https://leetcode.com/problems/number-of-atoms/?envType=daily-question&envId=2024-07-14
// Sorting + Stack (1h)

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();

        stack<pair<string, int>> stk;
        int i = 0;
        while (i < n) {
            if (isupper(formula[i])) {
                // Start with uppercase 
                string elem;
                elem += formula[i++];
                
                // Collect the rest of lowercase
                while (i < n && islower(formula[i])) {
                    elem += formula[i++];
                }
                
                int count = 0;
                // Collect the number
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i++] - '0');
                }
                
                if (count == 0) count = 1; // No number 
                
                stk.push({elem, count});
            } 
            else if (formula[i] == '(') {
                stk.push({"(", 1});
                i++;
            } 
            else if (formula[i] == ')') {
                int count = 0;
                i++;
                
                // Collect the number after ')'
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i++] - '0');
                }
                
                if (count == 0) count = 1; // No number
                
                // Pop from stack until '('
                stack<pair<string, int>> temp;
                while (!stk.empty() && stk.top().first != "(") {
                    auto top = stk.top(); stk.pop();
                    if (top.first != "(") {
                        top.second *= count;
                        temp.push(top);
                    }
                }
                
                // Pop '(' from stack
                if (!stk.empty()) stk.pop();
                
                // Push back to main stack
                while (!temp.empty()) {
                    stk.push(temp.top());
                    temp.pop();
                }
            }
        }
        
        // Accumulate counts using unordered_map
        unordered_map<string, int> counts;
        while (!stk.empty()) {
            auto top = stk.top(); stk.pop();
            counts[top.first] += top.second;
        }
        
        // Sort elements alphabetically
        vector<pair<string, int>> sorted_counts(counts.begin(), counts.end());
        sort(sorted_counts.begin(), sorted_counts.end());
        
        // Construct the result string
        string result;
        for (auto& p : sorted_counts) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }
        
        return result;
    }
};
