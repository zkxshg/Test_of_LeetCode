// DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = matrix.size();
        if (len < 1) return 0;
        int wid = matrix[0].size();
        if (wid < 1) return 0;
        vector<vector<int>> dpTable(len, vector<int>(wid));
        for (int i = 0; i < len; i++){
            for (int j = 0; j < wid; j++){
                if (i == 0 || j == 0) {
                    if (matrix[i][j] == '1') {
                        dpTable[i][j] = 1;
                        maxl = max(maxl, dpTable[i][j]);
                    }
                }
                else {
                    if (matrix[i][j] == '0') continue;
                    else {
                        dpTable[i][j] = min({dpTable[i - 1][j], dpTable[i][j - 1], dpTable[i - 1][j - 1]}) + 1;
                        maxl = max(maxl, dpTable[i][j]);
                    }
                }
            }
        }
        return maxl * maxl;
    }  
};

// exausted search
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = matrix.size();
        if (len < 1) return 0;
        int wid = matrix[0].size();
        if (wid < 1) return 0;
        
        int maxl = 0, squ = 0;
        
        for (int i = len - 1; i >= 0; i--){
            for (int j = wid - 1; j >= 0; j--){
                squ = 0;
                
                if (matrix[i][j] == '1'){
                    squ = 1;
                    maxl = max(maxl, squ); 
                }
                else continue;
                
                if (i == 0 || j == 0) continue;
                
                vector<vector<int>> points;
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                points.push_back(temp);
                
                while (ifSqua(points, matrix)) squ++;
                
                maxl = max(maxl, squ);
            }
        }
        return maxl * maxl;
    }
    
    bool ifSqua(vector<vector<int>>& points, vector<vector<char>>& matrix) {
        int num = points.size(), cou = 0;
        
        while (cou < num) {
            int x = points[0][0], y = points[0][1];
            if (x == 0 || y == 0) return false;
            
            if (matrix[x - 1][y] == '0') return false;
            else {
                vector<int> temp;
                temp.push_back(x - 1);
                temp.push_back(y);
                if(find(points.begin(), points.end(), temp) == points.end())
                    points.push_back(temp);
            }
            
            if (matrix[x - 1][y - 1] == '0') return false;
            else {
                vector<int> temp;
                temp.push_back(x - 1);
                temp.push_back(y - 1);
                if(find(points.begin(), points.end(), temp) == points.end())
                    points.push_back(temp);
            }
            
            if (matrix[x][y - 1] == '0') return false;
            else {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y - 1);
                if(find(points.begin(), points.end(), temp) == points.end())
                    points.push_back(temp);
            }
            points.erase(points.begin());
            cou++;
        }
        return true;
    }
};
