// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// DP

class Solution {
public:
    string add(string str, int dig) {
        int pos = -1; char dc = '0' + dig; //cout << str << "+" << dig << "=";
        
        for (int i = 0; i < str.size(); i++) 
            if (str[i] <= dc) {
                pos = i; break;
            }

        string res;
        if (pos < 0) res = str + dc;
        else res = str.substr(0, pos) + dc + str.substr(pos); //cout << res << endl; 
        return res;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int, int> c2d;
        
        for (int i = 0; i < 9; i++) c2d[cost[i]] = max(c2d[cost[i]], i + 1);
        
        vector<int> cand;
        for (auto& p : c2d) cand.push_back(p.first);
        
        vector<string> dp(target + 1, "");
        
        for (int i = 0; i <= target; i++) {
            if (i > 0 && dp[i].empty()) continue;
            
            string dij = dp[i];
            
            for (int c : cand) {
                if (i + c <= target) {
                    string larger = add(dij, c2d[c]);
                    
                    if (larger.size() > dp[i + c].size() || 
                        (larger.size() == dp[i + c].size() && larger > dp[i + c]))
                        dp[i + c] = larger;
                }
            }
        }
        
        //for (int i = 0; i <= target; i++) cout << i << ":" << dp[i] << endl;
        if (dp[target].empty()) return "0";
        return dp[target];
    }
};
