// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// array
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> C(n);
        for (int i = 0; i < n; i++) C[i] = i + 1;
        
        int st = 0;
        while (C.size() > 1) {
            int fail = (st + k - 1) % C.size();
            C.erase(C.begin() + fail);
            st = fail % C.size();
        }
        return C[0];
    }
};
