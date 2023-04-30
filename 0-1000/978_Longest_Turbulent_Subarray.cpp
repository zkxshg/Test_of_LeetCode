// https://leetcode.com/problems/longest-turbulent-subarray/
// sliding window

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> minus(n - 1);
        for (int i = 1; i < n; i++) minus[i - 1] = arr[i] - arr[i - 1];
        
        int st = 0, res = 0; bool inc = true; n = n - 1;
        while (st < n) {
            if (minus[st] == 0) {
                st++; continue;
            }
            
            if (minus[st] < 0) inc = false;
            else inc = true;
            st++;
            
            int tres = 1;
            while (st < n) {
                if (inc && minus[st] < 0) {
                    inc = false; st++; tres++;
                }
                else if (!inc && minus[st] > 0) {
                    inc = true; st++; tres++;
                }
                else break;
            }
            
            res = max(res, tres);
        }
        
        return res + 1;
        
    }
};
