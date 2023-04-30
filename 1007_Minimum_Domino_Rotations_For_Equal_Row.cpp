// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// hash map
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int len = A.size();
        
        unordered_map<int, int> domCou;
        for (int i = 0; i < len; i++) {
            if (A[i] == B[i]) domCou[A[i]]++;
            else {
                domCou[A[i]]++;
                domCou[B[i]]++;
            }
        }
        
        vector<int> validNum;
        for (auto& it : domCou) {
            if (it.second >= len) validNum.push_back(it.first);
        }
        
        if (validNum.size() <= 0) return -1;

        int result = len + 1;
        for (int vn : validNum) {
            int An = len - count(A.begin(), A.end(), vn);
            int Bn = len - count(B.begin(), B.end(), vn);
            int minR = min(An, Bn);
            
            if (minR < result) result = minR;
        }
        
        return result;
    }
};
