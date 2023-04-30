// hash table
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int len = mat.size(), wid = mat[0].size();
        
        unordered_map<int, int> rowDict;
        unordered_map<int, int> colDict;
        vector<int> is;
        vector<int> js;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (mat[i][j]) {
                    rowDict[i]++;
                    colDict[j]++;
                    is.push_back(i);
                    js.push_back(j);
                }
            }
        }
        
        int result = 0;
        for (int k = 0; k < is.size(); k++) {
            int i = is[k], j = js[k];
            if (rowDict[i] == 1 && colDict[j] == 1) result++;
        }
        
        return result;
    }
};
