//https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// math + greedy
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for (int i : position) {
            if (i % 2 == 1) odd += 1;
            else even += 1;
        }
        return min(even, odd);
    }
};
