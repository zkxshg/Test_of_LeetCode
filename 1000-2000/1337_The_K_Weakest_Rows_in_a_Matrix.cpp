// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix
// BFS
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int> > dic(n + 1);
        for (int i = 0; i < m; i++) {
            vector<int> v = mat[i];
            int sold = accumulate(v.begin(), v.end(), 0);
            dic[sold].push_back(i);
        }
        
        vector<int> res;
        for (vector<int> v : dic) {
            for (int i : v) {
                res.push_back(i); k--;
                if (k <= 0) break;
            }
            if (k <= 0) break;
        }
        return res;
    }
};
