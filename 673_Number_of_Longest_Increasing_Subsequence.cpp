// DP
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size(); if (len < 2) return len;
        
        vector<int> leng(len); leng[0] = 1;
        vector<int> combi(len, 1); combi[0] = 1;
        
        int maxLen = 1;
        for (int i = 1; i < len; i++) {
            int local = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) local = max(local, leng[j] + 1);
            }
            leng[i] = local;
            if (local > maxLen) maxLen = local;
            
            int temC = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && leng[j] == local - 1) temC += combi[j];
            }
            combi[i] = max(combi[i], temC);
        }

        int result = 0;
        for (int i = 0; i < len; i++) {
            if (leng[i] == maxLen) result += combi[i];
        }
        return result;
    }
};
