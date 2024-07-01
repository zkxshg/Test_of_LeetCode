// https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01
// Array

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            // Use bit manipulation to check if the number is odd
            if (num & 1) { // equivalent to (num % 2 != 0)
                count++;
                if (count == 3) {
                    return true;
                }
            } else {
                count = 0; // reset count if the number is even
            }
        }
        return false;
    }
};
