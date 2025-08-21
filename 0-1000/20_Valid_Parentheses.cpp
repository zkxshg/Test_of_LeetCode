// stack
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        
        vector<int> st;
        for (char ch : s) {
            if (st.empty()) st.push_back(ch);
            else if (which(st.back()) >0 && which(st.back()) + which(ch) == 0) st.pop_back();
            else st.push_back(ch);
        }
        
        if (st.empty()) return true;
        return false;
    }
    int which(char ch){
        int order = 0;
        if (ch == '(') order = 1;
        else if (ch == '{') order = 2;
        else if (ch == '[') order = 3;
        else if (ch == ')') order = -1;
        else if (ch == '}') order = -2;
        else if (ch == ']') order = -3;
        return order;
    }
};

// string stacks = s; int top = 1; if ((w2+w1) == 0) top -= 1; else top += 1; if (top == 0) return true;
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if (len == 0) return true;
        string stacks = s;
        int top = 1;
        for (int i = 1; i < len; i++)
        {
            if (top == 0) {
                stacks[top] = s[i];
                top += 1;
                continue;
            }
            
            int w1 = whichBrackets(stacks[top-1]);
            int w2 = whichBrackets(s[i]);
            
            if ((w2+w1) == 0) top -= 1;
            else if ((w1 * w2) < 0) return false;
            else {
                stacks[top] = s[i];
                top += 1;
            }
        }
        
        if (top == 0) return true;
        else return false;
    }
    int whichBrackets(char ch){
        int order = 0;
        if (ch == '(') order = 1;
        else if (ch == '{') order = 2;
        else if (ch == '[') order = 3;
        else if (ch == ')') order = -1;
        else if (ch == '}') order = -2;
        else if (ch == ']') order = -3;
        return order;
    }
};
