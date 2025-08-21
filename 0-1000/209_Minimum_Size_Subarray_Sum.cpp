// https://leetcode.com/problems/minimum-size-subarray-sum/
// sliding window

class Solution {
public:
    #define ll long long
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        ll sum = nums[0];
        int st = 0, en = 0, res = INT_MAX;
        
        if (sum >= target) res = min(res, en - st + 1);
        
        while (en < n || sum >= target) {
            if (sum < target || st == en) {
                en++;
                if (en < n) sum += nums[en];
            }
            else {
                sum -= nums[st]; st++; 
            }
            
            if (sum >= target) res = min(res, en - st + 1);
            // cout << st << ":" << en << "=" << sum << endl;
        }
        
        if (res == INT_MAX) return 0;

        return res;
        
    }
};
