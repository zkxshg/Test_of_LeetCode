// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
// string

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0, n = sentences.size();
        for (auto& s : sentences) {
            int sres = 0;
            for (char c : s)
                if (c == ' ') sres++;
            res = max(res, sres + 1);
        }
        return res;
    }
};
