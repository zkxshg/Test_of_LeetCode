// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
// heap

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();

        make_heap(piles.begin(), piles.end());

        for (int i = 0; i < k; i++) {
            int m = piles.front();

            pop_heap(piles.begin(), piles.end()); piles.pop_back();

            int m2 = m - m / 2;

            piles.push_back(m2); push_heap(piles.begin(), piles.end());
        }

        sort_heap(piles.begin(), piles.end());

        int res = 0;
        for (int i : piles) res += i;
        return res;
    }
};
