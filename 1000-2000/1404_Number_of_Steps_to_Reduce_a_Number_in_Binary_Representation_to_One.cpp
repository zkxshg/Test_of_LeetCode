// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2024-05-29
// bit manipulation

class Solution {
public:
    int numSteps(std::string s) {
        int steps = 0;
        
        // Iterate through the string from right to left
        while (s.size() > 1) {
            // If the rightmost bit is 0, remove it (divide by 2)
            if (s.back() == '0') {
                s.pop_back(); 
                steps++;
            } 
            // If the rightmost bit is 1, find the nearest 0 and flip all 1s to 0s
            else {
                steps++;
                while (s.size() > 1 && s.back() == '1') {
                    s.pop_back(); 
                    steps++;
                }
                // If we haven't reached the end of the string, flip the nearest 0 to 1
                if (s.size() > 1) s.back() = '1';
                else steps++;
            }
        }
        
        return steps;
    }
};
