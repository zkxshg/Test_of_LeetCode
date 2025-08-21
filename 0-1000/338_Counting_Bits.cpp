// numof1[i] = bitset<sizeof(i)*8>(i).count();
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> numof1(num+1);
        for (int i = 1; i < num+1; i++) numof1[i] = bitset<sizeof(i)*8>(i).count();
        return numof1;
    }
};
