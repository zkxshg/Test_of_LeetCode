// two pointers
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        vector<int> res(len);
        int od = 0, ev = 1;
        for (int i : A) {
            if (i&1) {
                res[ev] = i;
                ev += 2;
            }
            else {
                res[od] = i;
                od += 2;
            }
        }
        return res;
    }
};
