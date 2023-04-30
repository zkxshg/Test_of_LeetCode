// https://leetcode.com/problems/reverse-bits/
// uint32_t -> bitset<32> -> reverse(string) -> bitset<32> -> uint32_t
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bits(n);
        string nstr = bits.to_string();
        reverse(nstr.begin(), nstr.end());
        bitset<32> bitsR(nstr);
        uint32_t res = bitsR.to_ulong();
        return res;
    }
};
