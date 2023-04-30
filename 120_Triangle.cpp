// https://leetcode.com/problems/triangle/
// staightforward search / DP
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rownum = triangle.size();
        if (rownum == 0) return 0;
        if (rownum == 1) return triangle[0][0];
        vector<vector<int>> rowMinL(2, vector<int>(rownum));
        rowMinL[0][0] = triangle[0][0];
        rowlen(triangle, rowMinL, 0);
        int minl = INT_MAX;
        for (int i = 0; i < rownum; i++){
            int temp = rowMinL[0][i];
            if (minl > temp) minl = temp;
        }
        return minl;
    }
    
    void rowlen(vector<vector<int>>& triangle, vector<vector<int>>& rowMinL, int rownum){
        if (rownum == 0) rowlen(triangle, rowMinL, 1);
        else{
            int bottomrow = triangle.size() - 1;
            rowMinL[1][0] = triangle[rownum][0] + rowMinL[0][0]; 
            rowMinL[1][rownum] = triangle[rownum][rownum] + rowMinL[0][rownum - 1];
            for(int i = 1; i < rownum; i++){
                int leftL = triangle[rownum][i] + rowMinL[0][i - 1];
                int rightL= triangle[rownum][i] + rowMinL[0][i];
                if (leftL < rightL) rowMinL[1][i] = leftL;
                else rowMinL[1][i] = rightL;
            }
            rowMinL[0] = rowMinL[1];
            if (rownum < bottomrow) rowlen(triangle, rowMinL, rownum+1);                                 
        }
    }
};
