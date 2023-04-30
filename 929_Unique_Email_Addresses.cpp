// https://leetcode.com/problems/unique-email-addresses/
// hash map

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> dict;
        
        int res = 0;
        for (auto& s : emails) {
            string add = "";
            
            bool local = true;
            
            int n = s.size(), pos = 0;
            while (pos < n) {
                if (local) {
                    if (s[pos] == '+') {
                        while (s[pos] != '@') pos++;
                        local = false;
                        add += s[pos];
                    }
                    else if (s[pos] != '.') add += s[pos];
                    
                    if (s[pos] == '@') local = false;
                } 
                else add += s[pos];

                pos++;
            }
            
            if (!dict[add]) {
                dict[add] = 1; res++;
            }
        }
        
        return res;
    }
};
