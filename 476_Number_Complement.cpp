// bit manipulation
class Solution {
public:
    int findComplement(int num) {
        if (num == 0 || num == 1) return 1 - num;
        int spos = 31;
        while(spos > 0) {
            if(num & (1 << spos)) break;
            spos--;
        }
        for (int i = 0; i < spos + 1; i++) num ^= (1 << i);
        return num;
    }
};
