// https://leetcode.com/problems/global-and-local-inversions/
// math: O(n)
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int pre_max = -1, len = A.size();
        
        for (int i = 1; i < len; i++) {
            if (A[i] < pre_max) return false;
            pre_max = max(pre_max, A[i - 1]);
        }
        return true;
    }
};

// DP: O(n^2)
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int glo = 0, loc = 0, len = A.size();
        vector<int> sco(len); sco[A[0]] = 1;
        for (int i = 1; i < len; i++) {
            if (A[i] < A[i - 1]) loc++;
            
            for (int j = A[i] + 1; j < len; j++) glo += sco[j];
            sco[A[i]] = 1;
        }
        return glo == loc;
    }
};
