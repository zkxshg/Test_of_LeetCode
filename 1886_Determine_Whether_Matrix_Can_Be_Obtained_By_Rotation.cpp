// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// hash 
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if (n == 1) return mat[0][0] == target[0][0];
        
        for (int i = 0; i < n / 2; i++) {
            vector<int> a(4); vector<int> b(4);
            
            for (int j = i; j < n - i; j++) {
                a[0] += mat[i][j] * pow(10, j - i); b[0] += target[i][j] * pow(10, j - i);
                
                a[1] += mat[j][n - 1 - i] * pow(10, j - i); b[1] += target[j][n - 1 - i] * pow(10, j - i);
                    
                a[2] += mat[n - 1 - i][n - 1 - j] * pow(10, j - i); b[2] += target[n - 1 - i][n - 1 - j] * pow(10, j - i);
                
                a[3] += mat[n - 1 - j][i] * pow(10, j - i); b[3] += target[n - 1 - j][i] * pow(10, j - i);
            }
            //for (int i = 0; i < 4; i++) cout << a[i] << ","; cout << endl;
            //for (int i = 0; i < 4; i++) cout << b[i] << ","; cout << endl;
            
            bool same = false;
            for (int j = 0; j < 4; j++) {
                if (a[0] == b[j] && a[1] == b[(j + 1) % 4] && a[2] == b[(j + 2) % 4] && a[3] == b[(j + 3) % 4]) {
                    same  = true; break;
                }
            }
            
            if (!same) return false;
            
        }
        
        return true;
        
    }
};
