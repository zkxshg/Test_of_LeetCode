// BFS
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int len = matrix.size(); if (len < 1) return matrix;
        int wid = matrix[0].size(); if (wid < 1) return matrix;
        
        vector<vector<int>> resM(len, vector<int>(wid, 10001));
         
        int totalNum = len * wid, step = 0;
        
        vector<int> xPos;
        vector<int> yPos;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (matrix[i][j] == 0) {
                    resM[i][j] = 0;
                    xPos.push_back(i);
                    yPos.push_back(j);
                    totalNum--;
                }
            }
        }

        while (totalNum > 0) {
            vector<int> xPosTemp;
            vector<int> yPosTemp;
            
            for (int i = 0; i < xPos.size(); i++) {
                int i1 = xPos[i], j1 = yPos[i];
                
                if (i1 > 0 && resM[i1 - 1][j1] > step + 1) {
                    resM[i1 - 1][j1] = step + 1;
                    xPosTemp.push_back(i1 - 1);
                    yPosTemp.push_back(j1);
                    totalNum--;
                }
                
                if (j1 > 0 && resM[i1][j1 - 1] > step + 1) {
                    resM[i1][j1 - 1] = step + 1;
                    xPosTemp.push_back(i1);
                    yPosTemp.push_back(j1 - 1);
                    totalNum--;
                }
                
                if (i1 < len - 1 && resM[i1 + 1][j1] > step + 1) {
                    resM[i1 + 1][j1] = step + 1;
                    xPosTemp.push_back(i1 + 1);
                    yPosTemp.push_back(j1);
                    totalNum--;
                }
                
                if (j1 < wid - 1 && resM[i1][j1 + 1] > step + 1) {
                    resM[i1][j1 + 1] = step + 1;
                    xPosTemp.push_back(i1);
                    yPosTemp.push_back(j1 + 1);
                    totalNum--;
                }
            }  
            
            step++;
            xPos = xPosTemp;
            yPos = yPosTemp;
        }
        
        return resM;
    }
    
};
