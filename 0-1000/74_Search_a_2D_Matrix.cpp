// binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); if (m < 1) return false;
        int n = matrix[0].size(); if (n < 1) return false;
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
        
        int row = searchRow(matrix, target, 0, m - 1);
        int col = searchCol(matrix[row], target, 0, n - 1);
        
        return matrix[row][col] == target;
    }
    
    int searchRow(vector<vector<int>>& matrix, int tar, int st, int en) {
        if (st == en) return st; 
        int mid = (st + en) / 2;
        if (matrix[mid][0] <= tar && matrix[mid + 1][0] > tar) return mid;
        else if (matrix[mid][0] > tar) return searchRow(matrix, tar, st, mid);
        else return searchRow(matrix, tar, mid + 1, en);
    }
    
    int searchCol(vector<int>& matrix, int tar, int st, int en) {
        if (st == en) return st;
        int mid = (st + en) / 2;
        if (matrix[mid] <= tar && matrix[mid + 1] > tar) return mid;
        else if (matrix[mid] > tar) return searchCol(matrix, tar, st, mid);
        else return searchCol(matrix, tar, mid + 1, en);
    }
};
