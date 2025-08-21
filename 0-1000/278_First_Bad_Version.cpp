// binary search
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 0) return 0;
        if (isBadVersion(1)) return 1;
        
        unsigned int start = 1;
        unsigned int least = n;
        while (least - start >= 0){
            if (least - start <= 1) return least;
            unsigned int k = (least + start) / 2;
            if (isBadVersion(k)) least = k;
            else start = k;
        }
        return -1;
    }
};
