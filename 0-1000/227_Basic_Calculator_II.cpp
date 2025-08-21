// stack + string trans
class Solution {
public:
    int calculate(string s) {
        int len = s.size(); if (len < 1) return 0;
        
        int pos = 0, res = 0;
        
        vector<int> temN = getNum(s, 0);
        pos += temN[1];
        res = temN[0];
        
        stack<int> numSt; numSt.push(res);
        stack<char> sigSt;
       
        while (pos < len) {
            if (s[pos] >= '0' && s[pos] <= '9') {
                int temres = 0;
                while (s[pos] >= '0' && s[pos] <= '9') temres = temres * 10 + (s[pos++] - '0');
                
                if (sigSt.top() == '+' || sigSt.top() == '-') numSt.push(temres);
                else if (sigSt.top() == '*' ) {
                    numSt.top() *= temres;
                    sigSt.pop();
                }
                else if (sigSt.top() == '/' ) {
                    numSt.top() /= temres;
                    sigSt.pop();
                }
            }
            else if (s[pos] == ' ') pos++;
            else {
                sigSt.push(s[pos]);
                pos++;
            }
            
            if (pos  < 0) break;
        }
        
        int result = 0;

        while (!sigSt.empty()) {
            int lastN = numSt.top();
            numSt.pop();
            
            if (sigSt.top() == '+')  result += lastN;
            else if (sigSt.top() == '-') result -= lastN;
            
            sigSt.pop(); 
        }
        
        result += numSt.top();
        
        return result;
    }
    
    vector<int> getNum(string s, int p) {
        int len = s.size();
        int pos = p;
        int lv = 0, temp = 0;
        
        while (s[pos] == ' ') {
            pos++;
            lv++;
        }
        
        vector<int> res(2);
        
        if (pos < len - 1 && (s[pos] < '0' || s[pos] > '9')) {
            res[0] = s[pos] - '0'; 
            res[1] = 1;
            return res;
        }
        
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            temp = temp * 10 + (s[pos] - '0');
            pos++;
            lv++;
        }
        
        
        res[0] = temp; res[1] = lv;
        
        return res;
    }
};
