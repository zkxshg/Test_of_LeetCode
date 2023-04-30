// divide-and-conquer: O((m+n)logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return search(matrix, target, 0, m - 1, 0, n - 1);
    }
    
    bool search(vector<vector<int>>& M, int t, int x1, int x2, int y1, int y2) {
        if (x1 > x2 || y1 > y2) return false;
        
        if (x2 == x1 || y2 == y1) {
            bool get = false;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (M[i][j] == t) {
                        get = true; break;
                    }
                }
            }
            return get;
        }
        
        //cout << "x1 = " << x1 << ", x2 = " << x2 << ", y1 = " << y1 << ", y2 = " << y2 << endl;
        
        int dia = 0;
        
        while (x1 + dia < x2 && y1 + dia < y2 && M[x1 + dia][y1 + dia] < t) dia++;
        
        if (M[x1 + dia][y1 + dia] == t) return true;
        
        if (M[x1 + dia][y1 + dia] < t) {
            if (x1 + dia == x2) return search(M, t, x1, x2, y1 + dia + 1, y2);
            else return search(M, t, x1 + dia + 1, x2, y1, y2);
        }
        
        if (dia == 0) return false;
        
        bool ld = search(M, t, x1 + dia, x2, y1, y1 + dia - 1);
        bool ru = search(M, t, x1, x1 + dia - 1, y1 + dia, y2);
        
        return (ld || ru);
    }
};
