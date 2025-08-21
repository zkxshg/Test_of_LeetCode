//https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
// Geometry

class Solution {
public:
    #define sp stockPrices
    
    bool compare(int a, int b, int c, int d) {
       
        if (b == 0 && d == 0) return true;
        if (b == 0) return false;
        if (d == 0) return false;
        int x = __gcd(a, b);
        a = a / x;
        b = b / x;
        
        int y = __gcd(c, d);
        c = c / y;
        d = d / y;
        
        return (a == c & b == d);
    }
    
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = sp.size(), res = 1;
        int x0 = 0, y0 = 0;
        if (n < 2) return 0;
        
        sort(sp.begin(), sp.end());
        
        bool vtc = false;
        
        if (sp[0][0] == sp[1][0]) vtc = true;
        else {
            y0 = sp[1][1] - sp[0][1]; x0 = sp[1][0] - sp[0][0];
        }

        for (int i = 2; i < n; i++) { 
            if (sp[i][0] == sp[i - 1][0]) {
                if (vtc) continue;
                else {
                    res++; vtc = true;
                }
            }
            else {
                int y1 = sp[i][1] - sp[i - 1][1], x1 = sp[i][0] - sp[i - 1][0];
                
                if (vtc) {
                    res++; vtc = false; x0 = x1, y0 = y1;
                }
                else if (!compare(y0, x0, y1, x1)) {
                    res++; x0 = x1; y0 = y1;
                }
            }
        }
        
        return res;
    }
};
