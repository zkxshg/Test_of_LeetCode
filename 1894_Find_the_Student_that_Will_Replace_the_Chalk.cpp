// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// math + greedy
class Solution {
public:
    #define ll long long
    
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        
        vector<ll> cost(n); cost[0] = chalk[0];
        for (int i = 1; i < n; i++) cost[i] = cost[i - 1] + chalk[i];
        
        k %= cost[n - 1];
        
        for (int i = 0; i < n; i++) 
            if (k < cost[i])
                return i;
        
        return 0;
    }
};
