class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) sum += (s[s.size() - 1 - i]-'A'+1) * pow(26, i);
        return sum;
    }
};
