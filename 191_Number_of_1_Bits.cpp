// uint32_t -> bitset<32> -> string
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bits(n);
        string nstr = bits.to_string();
        int counter = 0;
        for (int i = 0; i < nstr.size(); i++){
            if (nstr[i] == '1') counter++;
        }
        return counter;
    }
};
