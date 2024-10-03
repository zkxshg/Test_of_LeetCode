// https://leetcode.com/problems/different-ways-to-add-parentheses/?envType=daily-question&envId=2024-09-15
// Recursion + DP

class Solution {
public:
    unordered_map<std::string, std::vector<int>> memo;
    
    std::vector<int> compute(const std::string& expr) {
        // Check if we already computed this expression
        if (memo.find(expr) != memo.end()) {
            return memo[expr];
        }

        std::vector<int> results;
        bool isNumber = true;

        for (int i = 0; i < expr.size(); i++) {
            // Check for operators
            if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                isNumber = false;
                std::string left = expr.substr(0, i);
                std::string right = expr.substr(i + 1);
                
                std::vector<int> leftResults = compute(left);
                std::vector<int> rightResults = compute(right);
                
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (expr[i] == '+') results.push_back(l + r);
                        else if (expr[i] == '-') results.push_back(l - r);
                        else if (expr[i] == '*') results.push_back(l * r);
                    }
                }
            }
        }

        // If no operators were found, the expression is a single number
        if (isNumber) {
            results.push_back(std::stoi(expr));
        }

        // Memoize the results
        memo[expr] = results;
        return results;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        return compute(expression);
    }
};
