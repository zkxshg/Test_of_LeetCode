// https://leetcode.com/problems/palindrome-partitioning-iv/
// DP

class Solution {
public:
    bool ifPali(string& s, int st, int en) {
        int l = st, r = en;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    bool checkPartitioning(string s) {
        int n = s.size();
        
        unordered_map<int, int> prePali;
        for (int i = 0; i < n; i++)
            if (ifPali(s, 0, i))
                prePali[i]++;
        
        unordered_map<int, int> sufPali;
        for (int i = 0; i < n; i++)
            if (ifPali(s, i, n - 1))
                sufPali[i]++;
        
        for (int i = 0; i < n - 2; i++) {
            if (!prePali[i]) continue;
            
            for (int j = i + 2; j < n; j++) {
                if (!sufPali[j]) continue;
                
                if (j - i == 2) return true;
                
                if (ifPali(s, i + 1, j - 1)) return true;
            }
        }
        
        return false;
    }
};
