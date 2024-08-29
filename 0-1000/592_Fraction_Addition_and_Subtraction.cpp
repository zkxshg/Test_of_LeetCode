// https://leetcode.com/problems/fraction-addition-and-subtraction/?envType=daily-question&envId=2024-08-17
// Math

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Start with 0/1
        
        int i = 0;
        while (i < expression.size()) {
            int sign = 1;
            if (expression[i] == '-') {
                sign = -1;
                i++;
            } else if (expression[i] == '+') {
                i++;
            }
            
            int num = 0, denom = 0;
            while (i < expression.size() && expression[i] != '/') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i++; // Skip the '/'
            while (i < expression.size() && expression[i] != '+' && expression[i] != '-') {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }
            
            num *= sign;
            
            // Add to the overall fraction
            numerator = numerator * denom + num * denominator;
            denominator *= denom;
            
            // Simplify the fraction
            int gcd = __gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

        if (denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        
        return to_string(numerator) + '/' + to_string(denominator);
    }
};
