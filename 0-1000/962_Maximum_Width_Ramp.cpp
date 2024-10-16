// https://leetcode.com/problems/maximum-width-ramp/?envType=daily-question&envId=2024-10-10
// Monotonic Stack + Sorting

class Solution {
public:
    #define pii pair<int, int>
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<pii> sn;
        for (int i = 0; i < n; i++) sn.push_back({nums[i], i});
        sort(sn.begin(), sn.end());

        int minPos = sn[0].second, res = 0;
        for (int i = 1; i < n; i++) {
            pii& p = sn[i];
            if (p.second > minPos) res = max(res, p.second - minPos);
            else minPos = p.second;
        }

        return res;
    }
};
