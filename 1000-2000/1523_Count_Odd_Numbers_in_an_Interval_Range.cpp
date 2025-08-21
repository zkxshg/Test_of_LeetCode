// math
class Solution {
public:
    int countOdds(int low, int high) {
        if ((high - low) % 2) return (high - low + 1) / 2;
        return (high - low) / 2 + low % 2;
    }
};
