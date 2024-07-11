// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11
// Stack

class Solution {
public:
     string reverseParentheses(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                // Pop characters until '('
                string temp;
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                stk.pop(); // Pop the '('

                // Reverse substring back to stack
                for (char ch : temp) {
                    stk.push(ch);
                }
            } else {
                stk.push(c);
            }
        }
        
        // Reverse to the result
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};
