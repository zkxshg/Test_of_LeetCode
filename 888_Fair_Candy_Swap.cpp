// https://leetcode.com/problems/fair-candy-swap/
// hash table

class Solution {
public:
    #define AS aliceSizes
    #define BS bobSizes
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int an = AS.size(), bn = BS.size();
        
        int asum = 0, bsum = 0;
        for (int i : AS) asum += i;
        for (int i : BS) bsum += i;
        
        unordered_map<int, int> bm; for (int i : BS) bm[i]++; 
        
        for (int ai : AS) {
            int bi_2 = bsum - asum + 2 * ai;
            
            if (bi_2 > 0 && !(bi_2 % 2)) {
                int bi = bi_2 / 2;
                if (bm[bi]) return {ai, bi};
            }
        }
        
        return {-1, -1};
    }
};
