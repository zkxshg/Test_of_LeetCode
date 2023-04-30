// DP
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int len = nums.size(); if (len == 1) return 1;
        
        vector<int> evenSum(len + 1, 0);
        vector<int> oddSum(len + 1, 0);
        
        for (int i = len - 1; i >= 0; i--) {
            if (i % 2 == 1) {
                evenSum[i] = evenSum[i + 1];
                oddSum[i] = oddSum[i + 1] + nums[i];
            } else {
                oddSum[i] = oddSum[i + 1];
                evenSum[i] = evenSum[i + 1] + nums[i];
            }
        }
        
        int oddR = oddSum[0], evenR = evenSum[0];
        
        int res = 0;
        for (int i = 0; i < len; i++){
            if (i % 2 == 1) {
                int oddNew = oddR - nums[i] - oddSum[i + 1] + evenSum[i + 1];
                int evenNew = evenR + oddSum[i + 1] - evenSum[i + 1];
                if (oddNew == evenNew) res++;
            }
            else {
                int oddNew = oddR - oddSum[i + 1] + evenSum[i + 1];
                int evenNew = evenR - nums[i]+ oddSum[i + 1] - evenSum[i + 1];
                if (oddNew == evenNew) res++;
            }
        }
        
        return res;
    }
};
