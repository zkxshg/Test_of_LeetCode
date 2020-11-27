// divide and conquer
class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size(); if (len == 1) return len >= k;
        
        vector<pair<int, int>> st2en; st2en.push_back(make_pair(0, len - 1));
        
        int res = 0;
        while (!st2en.empty()) {
            vector<pair<int, int>> temp;
            
            for (pair<int, int> pr : st2en) {
                int start = pr.first, last = pr.second;
                
                vector<int> freCt(26, 0);
                for (int i = start; i <= last; i++) freCt[s[i] - 'a']++;
                
                bool conti = true;
                int maxLen = 0;
                for (int i = start; i <= last; i++) {
                    if (freCt[s[i] - 'a'] < k) {
                        conti = false;
                        if(i > start && (i - start) >= k) temp.push_back(make_pair(start, i - 1));
                        if(i < last && (last - i) >= k) temp.push_back(make_pair(i + 1, last));
                        break;
                    }
                }
                
                if (conti) res = max(res, last - start + 1);
            }
            
            st2en = temp;
        }
        
        return res;
    }
};
