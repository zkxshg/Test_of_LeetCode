// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
// DP + ordered_set

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        // pre sum
        vector<vector<int> > psum(m, vector<int>(n));
        
        for (int i = 0; i < n; i++) psum[0][i] = matrix[0][i]; // (0,0->n)
        
        // (1->m,j)
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                psum[i][j] = psum[i - 1][j] + matrix[i][j];
        
        // loop
        int res = -pow(10, 6);
        for (int x1 = 0; x1 < m; x1++) {
            for (int x2 = x1; x2 < m; x2++) {

                int rsum = 0;
                set<int> pos; set<int> neg;

                for (int y = 0; y < n; y++) {
                    rsum += psum[x2][y] - (x1 ? psum[x1 - 1][y] : 0);
                    
                    if (rsum <= k && k - rsum < k - res) res = rsum;
                    
                    if (rsum > k) {
                        for (const auto& s : pos) {
                            if (rsum - s <= k) {
                                if (k - (rsum - s) < k - res)
                                    res = rsum - s;
                                break;
                            }
                        }
                    }
                    else {
                        for (const auto& s : neg) {
                            if (rsum - s <= k) {
                                if (k - (rsum - s) < k - res)
                                    res = rsum - s;
                                break;
                            }
                        }
                    }
                    
                    if (rsum >= 0) pos.insert(rsum);
                    else neg.insert(rsum);
                }
            }
        }
        
        return res;
        
        
    }
};
