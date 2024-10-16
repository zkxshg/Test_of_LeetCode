// https://leetcode.com/problems/sentence-similarity-iii/?envType=daily-question&envId=2024-10-06
// Two Points

class Solution {
public:
    vector<string> parse(string sen) {
        vector<string> parseWords;

        string tem = "";
        for (char c : sen) {
            if (c == ' ') {
                parseWords.push_back(tem);
                tem = "";
            }
            else {
                tem += c;
            }
        }

        parseWords.push_back(tem);

        return parseWords;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) {
            string tem = sentence1;
            sentence1 = sentence2;
            sentence2 = tem;
        }
        
        vector<string> Words1 = parse(sentence1);
        vector<string> Words2 = parse(sentence2);

        int n1 = Words1.size(), n2= Words2.size();
        
        int st = 0, en = 1;
        while (st < n2) {
            if (Words1[st] == Words2[st]) st++;
            else break;
        }
        while (en <= n2 && n2 - en >= st) {
            if (Words1[n1 - en] == Words2[n2 - en]) en++;
            else break;
        }

        if (st > n2 - en) return true;
        return false;
    }
};
