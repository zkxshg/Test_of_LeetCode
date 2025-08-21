// https://leetcode.com/problems/max-points-on-a-line/
// math + geometry + hash map

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<double, double>, int> lines;  // <k, b> -> index

        unordered_map<int, int> ver;
        
        unordered_map<int, unordered_map<int, int> > fre;
        unordered_map<int, int> lineNum;
        
        int n = points.size(), ind = 1;
        if (n < 2) return 1;
        
        for (int i = 0; i < n - 1; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                
                double k, b;
                if (x1 == x2) {
                    // vertical
                    b = x1;
                    
                    // get index
                    int pin = 0;
                    if (ver[x1]) pin = ver[x1];
                    else {
                        ver[x1] = pin = ind; ind++;
                    }
                    
                    // judge if exist
                    int x1y1 = x1 * 1001 + y1, x2y2= x2 * 1001 + y2;
                    
                    if (!fre[pin][x1y1]) {
                        fre[pin][x1y1]++; lineNum[pin]++;
                    }
                    
                    if (!fre[pin][x2y2]) {
                        fre[pin][x2y2]++; lineNum[pin]++;
                    }
                    
                    
                }
                else {
                    // calculate k, b
                    k = (double)(y1 - y2) / (x1 - x2);
                    b = y1 - k * x1;
                    
                    pair<double, double> L = make_pair(k, b); // line
                    
                    // get index
                    int pin = 0;
                    if (lines[L]) pin = lines[L];
                    else {
                        lines[L] = pin = ind; ind++;
                    }
                    
                    // judge if exist
                    int x1y1 = x1 * 1001 + y1, x2y2= x2 * 1001 + y2;
                    
                    if (!fre[pin][x1y1]) {
                        fre[pin][x1y1]++; lineNum[pin]++;
                    }
                    
                    if (!fre[pin][x2y2]) {
                        fre[pin][x2y2]++; lineNum[pin]++;
                    }
                }

            }
        }
        
        int res = 0;
        for (int i = 1; i < ind; i++) res = max(res, lineNum[i]);
        return res;
    }
};
