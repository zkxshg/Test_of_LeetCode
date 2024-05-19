// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/?envType=daily-question&envId=2024-05-19
// Greedy

class Solution {
public:
    #define ll long long

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        ll res = 0; ll posRes = 0; 
        int posNum = 0, minPos = INT_MAX, maxNeg = INT_MIN;
        for (int i : nums) {
            res += i;
            int div = (i^k) - i; 
            // cout << (i^k) << " - " << i << " = " << div << endl;

            if (div >= 0) {
                posNum++; minPos = min(minPos, div); posRes += div;
            }
            else maxNeg = max(maxNeg, div);
        }
        // cout << maxNeg << " + " << minPos << " = " << minPos + maxNeg << endl;

        if (posNum % 2 == 0) return res + posRes;

        if (minPos + maxNeg >= 0) return res + posRes + maxNeg;

        return res + posRes - minPos;
    }
};
