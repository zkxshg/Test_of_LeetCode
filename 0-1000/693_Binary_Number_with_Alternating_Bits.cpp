// bitset<sizeof(n)*8> bits(n)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<sizeof(n)*8> bits(n);
        string nstr = bits.to_string();
        while (nstr[0] == '0') nstr = nstr.substr(1, nstr.size()-1);
        bool alte = true;
        for (int i = 0; i < nstr.size() - 1; i++){
            if (nstr[i] == nstr[i+1]){
                alte = false;
                break;
            }
        }
        return alte;
    }
};
