// https://leetcode.com/problems/goal-parser-interpretation/
// string

class Solution {
public:
    string interpret(string command) {
        int n = command.size(), pos = 0;
        string res = "";
        while (pos < n) {
            if (command[pos] == 'G') {
                res += "G"; pos++;
            }
            else if (command[pos + 1] == ')') {
                res += 'o'; pos += 2;
            }
            else {
                res += "al"; pos += 4;
            }
        }
        return res;
    }
};
