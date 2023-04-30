// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        vector<int> H;
        make_heap(H.begin(), H.end()); 
        
        for (int i = 0; i < n; i++) {
            for (int j  = 0; j < n; j++) {
                if (H.size() < k) {
                    H.push_back(matrix[i][j]); push_heap(H.begin(), H.end());
                }
                else if (matrix[i][j] < H.front()) {
                    pop_heap(H.begin(), H.end()); H.pop_back(); 
                    H.push_back(matrix[i][j]); push_heap(H.begin(), H.end());
                }
            }
        }
        
        return H.front();
    }
};
