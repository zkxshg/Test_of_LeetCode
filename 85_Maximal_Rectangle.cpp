// https://leetcode.com/problems/maximal-rectangle/
// DP
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); if (!m) return 0;
        int n = matrix[0].size(); if (!n) return 0;
        
        vector<vector<int> > row(m, vector<int>(n));
        for (int i = 0; i < n; i++) row[0][i] = matrix[0][i] - '0';
        
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] - '0')
                    row[i][j] = row[i - 1][j] ? row[i - 1][j] + 1 : 1;
        
        vector<vector<int> > col(m, vector<int>(n));
        for (int i = 0; i < m; i++) col[i][0] = matrix[i][0] - '0';
        
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] - '0')
                    col[i][j] = col[i][j - 1] ? col[i][j - 1] + 1 : 1;
        
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // row back
                int collen = col[i][j], step = 0;
                while (i - step >= 0 && matrix[i - step][j] - '0') {
                    collen = min(collen, col[i - step][j]);
                    res = max(res, (step + 1) * collen);
                    step++;
                }
                
                // col back
                int rowlen = row[i][j]; step = 0;
                while (j - step >= 0 && matrix[i][j - step] - '0') {
                    rowlen = min(rowlen, row[i][j - step]);
                    res = max(res, (step + 1) * rowlen);
                    step++;
                }
            }
        }
                
        return res;
    }
};

// BFS
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); if (!m) return 0;
        int n = matrix[0].size(); if (!n) return 0;
        
        vector<vector<int> > cand;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                if (matrix[i][j] - '0')
                    cand.push_back({i, j, i, j});
        
        // for (auto& p : cand) cout << p[0] << "," << p[1] << "," << p[2] << "," << p[3] << endl;
        
        int res = 0; 
        
        if (!cand.empty()) res = 1;
        else return 0;
        
        while (!cand.empty()) {
            vector<vector<int> > tem;
            // cout << "|cand| = " << cand.size() << endl;
            
            for (vector<int>& p : cand) {
                int x1 = p[0], y1 = p[1], x2 = p[2], y2 = p[3];
                // cout << x1 << "," << y1 << " : " << x2 << "," << y2 << endl;
                
                // down
                if (x2 < m - 1) {
                    int step = 1; bool stop = false;
                    
                    while (!stop && x2 < m - step) {
                        bool vali = true;
                        for (int i = y1; i <= y2; i++) {
                            if (!(matrix[x2 + step][i]  - '0')) {
                                vali = false; break;
                            }
                        }

                        if (vali) {
                            res = max(res, (x2 + step - x1 + 1) * (y2 - y1 + 1));
                            tem.push_back({x1, y1, x2 + step, y2});
                        } 
                        else stop = true;
                        
                        step++;
                    }
                       
                }
                
                // right
                if (y2 < n - 1) {
                    int step = 1; bool stop = false;
                    
                    while (!stop && y2 < n - step) {
                        bool vali = true;
                        for (int i = x1; i <= x2; i++) {
                            if (!(matrix[i][y2 + step]  - '0')) {
                                vali = false; break;
                            }
                        }

                        if (vali) {
                            res = max(res, (x2 - x1 + 1) * (y2 + step - y1 + 1));
                            tem.push_back({x1, y1, x2, y2 + step});
                        }
                        else stop = true;
                        
                        step++;
                    }
                        
                } 
            }
            
            cand = tem;
        }
        return res;
    }
};
