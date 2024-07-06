// https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06
// Math

class Solution {
public:
    int passThePillow(int n, int time) {
        if (int(ceil((float)time / (n - 1))) & 1) return 1 + (time % (n - 1) > 0 ? time % (n - 1) : n - 1);
        return n - (time % (n - 1) > 0 ? time % (n - 1) : n - 1);
    }
};
