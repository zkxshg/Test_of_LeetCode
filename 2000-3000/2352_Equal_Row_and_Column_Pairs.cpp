// https://leetcode.com/problems/equal-row-and-column-pairs/description/
// Hash Map

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;

        unordered_map<string, int> htc;
        unordered_map<string, int> htr;

        for (int i = 0; i < n; i++) {
            string rs = ""; string cs = "";

            for (int j = 0; j < n; j++) {
                rs += to_string(grid[i][j]); rs += ",";
                cs += to_string(grid[j][i]); cs += ",";
            }
            
            if (htc.find(rs) != htc.end()) res += htc[rs]; 
            htr[rs]++;

            if (htr.find(cs) != htr.end()) res += htr[cs]; 
            htc[cs]++;

            //cout << rs << endl;
            //cout << cs << endl;
        }

        return res;
    }
};
