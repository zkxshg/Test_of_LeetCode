class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int, string> > words;
        string ts = "";
        int n = s.size(), pos = 0;
        while (pos < n) {
            if (s[pos] >= '0' && s[pos]  <= '9') words.push_back(make_pair(s[pos] - '0', ts));
            else if (s[pos] == ' ') ts = "";
            else ts += s[pos];
            pos++;
        }
        sort(words.begin(), words.end());
        string res = "";
        for (int i = 0; i < words.size(); i++) {
            res += words[i].second;
            if (i != words.size() - 1) res += ' ';
        }
        return res;
    }
};
