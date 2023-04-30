// string
class Solution {
public:
    int secondHighest(string s) {
        int ft = -1, sd = -1;
        
        for (char ch : s) {
            if (ch >= '0'&& ch <= '9') {
                int d = ch - '0';
                if (d == ft || d == sd) continue;
                
                if (d > ft) {
                    sd = ft; ft = d; 
                }
                else if (d > sd) sd = d;
            }
        }
        
        return sd;
    }
};
