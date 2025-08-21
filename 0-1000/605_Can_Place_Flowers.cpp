// array
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        
        int len = flowerbed.size();
        if (len < 1) return false;
        if (len == 1) {
            if (!flowerbed[0] && n < 2) return true;
            return false;
        }
        
        int pos = 1, valid = 0;
        
        if (!flowerbed[0] && !flowerbed[1]) {
            flowerbed[0] = 1;
            valid++;
        }
        
        while (pos < len - 1) {
            if (!flowerbed[pos]) {
                if (!flowerbed[pos - 1] && !flowerbed[pos + 1]) {
                    flowerbed[pos] = 1;
                    valid++;
                }        
            }
            pos++;
            if (valid >= n) return true;
        }
        
        if (!flowerbed[len - 2] && !flowerbed[len - 1]) {
            flowerbed[len - 1] = 1;
            valid++;
        }
        
        if (valid >= n) return true;
        return false;
    }
};
