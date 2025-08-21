// https://leetcode.com/problems/delete-and-earn/
// DP

class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int, int> > rle;
        
        sort(nums.begin(), nums.end());
        
        for (int i : nums) {
            if (rle.empty() || rle.back().first < i) rle.push_back(make_pair(i, 1));
            else if (rle.back().first == i) rle.back().second++;
        }
        
        int n = rle.size(); 
        if (n == 1) return rle[0].first * rle[0].second;
        
        vector<int> dp(n);
        
        dp[0] = rle[0].first * rle[0].second;
        
        if (rle[0].first + 1 == rle[1].first) dp[1] = max(dp[0], rle[1].first * rle[1].second);
        else dp[1] = dp[0] + rle[1].first * rle[1].second;
        
        for (int i = 2; i < n; i++) {
            if (rle[i - 1].first + 1 == rle[i].first) 
                dp[i] = max(dp[i - 1], dp[i - 2] +  rle[i].first * rle[i].second);
            else dp[i] = dp[i - 1] + rle[i].first * rle[i].second;
        }
        
        
        return dp[n - 1];
    }
};
