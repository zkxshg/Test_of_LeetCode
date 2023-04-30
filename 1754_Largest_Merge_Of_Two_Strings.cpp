// https://leetcode.com/problems/largest-merge-of-two-strings/
// Greedy

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        string res = "";
        int st1 = 0, st2 = 0;
        while (st1 < n1 || st2 < n2) {
            if (st1 >= n1) {
                res += word2[st2]; st2++;
            }
            else if (st2 >= n2) {
                res += word1[st1]; st1++;
            }
            else {
                if (word1[st1] > word2[st2]) {
                    res += word1[st1]; st1++;
                }
                else if (word1[st1] < word2[st2]) {
                    res += word2[st2]; st2++;
                }
                else if (word1.substr(st1) > word2.substr(st2))  {
                    res += word1[st1]; st1++;
                }
                else {
                    res += word2[st2]; st2++;
                }
            }
            // cout << res << "," << word1.substr(st1) << "," << word2.substr(st2) << endl;
        }
        
        return res;
    }
};
