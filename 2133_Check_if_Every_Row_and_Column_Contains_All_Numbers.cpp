// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
// hash table

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_map<int, unordered_map<int, int>> rows;
        unordered_map<int, unordered_map<int, int>> cols;
        
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i][matrix[i][j]]) return false;
                else rows[i][matrix[i][j]] = 1;

                if (cols[j][matrix[i][j]]) return false;
                else cols[j][matrix[i][j]] = 1;
            }
        }
        
        return true;
    }
};
