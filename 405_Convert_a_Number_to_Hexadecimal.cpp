// https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Bit maniputation

class Solution {
public:
    string toHex(int num) {
        string out;
        stringstream ss;

        ss << hex << num;
        ss >> out;
        //transform(out.begin(), out.end(), out.begin(), ::toupper);
        
        return out;
    }
};
