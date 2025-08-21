// 2106. Maximum Fruits Harvested After at Most K Steps
// Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
// Lang: C++
// Date: 2025-08-21 20:52:31.219 UTC

class Solution {
public:
    int getSteps(int leftPos, int rightPos, int startPos) {
        if (rightPos <= startPos)
            return startPos - leftPos;
        else if (leftPos >= startPos)
            return rightPos - startPos;
        else
            return min(2 * (startPos - leftPos) + (rightPos - startPos), 
                       2 * (rightPos - startPos) + (startPos - leftPos));
    }
    
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        int left = 0, right = 0, total = 0, maxFruits = 0;

        // Find the first position greater than or equal to (startPos - k)
        while (right < n && fruits[right][0] < startPos - k) right++;
        left = right;

        // Slide window to include positions from left to right within startPos ± k range
        while (right < n && fruits[right][0] <= startPos + k) {
            total += fruits[right][1];

            // Shrink window if steps exceed k
            while (left <= right && getSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                total -= fruits[left][1];
                left++;
            }

            maxFruits = max(maxFruits, total);
            right++;
        }

        return maxFruits;
    }
};
