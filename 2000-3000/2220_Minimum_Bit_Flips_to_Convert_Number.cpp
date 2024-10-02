// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-01
// Bit manipulation

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int ans = 0;
        
        while (xorResult) {
            ans += xorResult & 1; 
            xorResult >>= 1;
        }
        
        return ans;
    }
};
