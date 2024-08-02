// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/?envType=daily-question&envId=2024-08-02
// Sliding Window + Greedy

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre_1(n); 
        if (nums[0] == 1) pre_1[0] = 1;

        for (int i = 1; i < n; i++) {
            pre_1[i] = pre_1[i - 1];
            if (nums[i] == 1) pre_1[i]++;
        }

        int oneNum = pre_1[n - 1];

        if (oneNum < 1) return 0;

        int res = n + 1;
        for (int i = 0; i < n; i++) {
            if (i + oneNum <= n) {
                int st = i > 0 ? pre_1[i - 1] : 0;
                res = min(res, oneNum - (pre_1[i + oneNum - 1] - st));
            }
            else {
                int st = i > 0 ? pre_1[i - 1] : 0;
                int div1 = oneNum - st;
                int div2 = pre_1[oneNum - (n - i) - 1];
                res = min(res, oneNum - div1 - div2);
            }
        }

        return res;
    }
};
