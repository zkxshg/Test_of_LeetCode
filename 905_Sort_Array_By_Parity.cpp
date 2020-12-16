// two pointers
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        vector<int> res(len);
        int st = 0, en = len - 1;
        for (int i : A) {
            if (i&1) res[en--] = i;
            else res[st++] = i;
        }
        return res;
    }
};
