// string-permutation
class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        string nStr = to_string(n);
        next_permutation(nStr.begin(), nStr.end());
        int n2 = atoi(nStr.c_str());
        if (n2 > n) return n2;
        return -1;
    }
};
