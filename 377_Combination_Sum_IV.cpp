// https://leetcode.com/problems/combination-sum-iv/
// DP

class Solution {
public:
    #define ll long long
    ll ub = pow(2, 31) - 1;
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<ll> am(target + 1);  am[0] = 1;
        
        for (int i = nums[0]; i <= target; i++)
            for (int co : nums)
                if (i >= co)
                    am[i] = (am[i] + am[i - co]) % ub;
        
        // for (int i : am) cout << i << ","; cout << endl;
        
        return am[target];
        
        
    }
};
