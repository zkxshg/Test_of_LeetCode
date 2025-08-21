// match-based: A / B -> 1_in_A / 1_in_B -> C[-(len - 1), len - 1][-(wid - 1), wid - 1] -> max(C)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int len = A.size(), wid = A[0].size();
        vector<vector<int>> A1;
        vector<vector<int>> B1;
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (A[i][j]) {
                    vector<int> t1;
                    t1.push_back(i);
                    t1.push_back(j);
                    A1.push_back(t1);
                }
                if (B[i][j]) {
                    vector<int> t1;
                    t1.push_back(i);
                    t1.push_back(j);
                    B1.push_back(t1);
                }
            }
        }
        
        vector<vector<int>> C(2 * len, vector<int>(2 * wid, 0));
        for (int i = 0; i < A1.size(); i++) {
            for (int j = 0; j < B1.size(); j++) {
                C[B1[j][0] + len - A1[i][0]][B1[j][1] + wid - A1[i][1]]++;
            }
        }

        int result = 0;
        for (int i = 0; i < 2 * len; i++) {
            result = max(result, *max_element(C[i].begin(), C[i].end()));
        }
        return result;
    }
};
