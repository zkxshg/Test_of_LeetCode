// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// hash table
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int len = matrix.size(), wid = matrix[0].size();
        if (len == 1 && wid == 1)  return matrix[0];
        
        unordered_map<int, int> rowDict;
        vector<int> col_max(wid, 0);
        
        for (int i = 0; i < len; i++) {
            int row_min = *min_element(matrix[i].begin(), matrix[i].end());
            rowDict[row_min]++;
            for (int j = 0; j < wid; j++) {
                if (matrix[i][j] > col_max[j]) col_max[j] = matrix[i][j];
            } 
        }
        
        vector<int> result;
        for (int cm : col_max) {
            if (rowDict[cm]) result.push_back(cm); 
        }
        return result;
        
    }
};
