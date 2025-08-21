// https://leetcode.com/problems/minimum-average-difference/
// dp

class Solution {
public:
    #define ll long long
    
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        ll pre = 0, suf = 0;
        for (int i : nums) suf += i;
        
        int minAD = 100001, mind = 0;
        for (int i = 0; i < n; i++) {
            pre += nums[i]; suf -= nums[i];
            
            int Dsuf;
            if (i == n - 1) Dsuf = 0;
            else Dsuf = suf / (n - i - 1);
            
            int ad = abs(pre / (i + 1) - Dsuf);
            
            if (ad < minAD) {
                minAD = ad; mind = i;
            }
            
            //cout << i << ":" << pre / (i + 1) << "-" << Dsuf << "=" << ad << endl;
        }
        
        return mind;
    }
};
