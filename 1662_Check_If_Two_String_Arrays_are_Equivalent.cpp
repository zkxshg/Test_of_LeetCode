// string
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = ""; for (string str : word1) w1 += str;
        string w2 = ""; for (string str : word2) w2 += str;
        return w1 == w2;
    }
};
