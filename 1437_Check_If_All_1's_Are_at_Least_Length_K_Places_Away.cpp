// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// array
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = nums.size(), st = 0;
        while (st < len && !nums[st]) st++;
        
        int d = 0, res = 1e5 + 1;
        
        bool c = true; 
        for (int j = st + 1; j < len; j++) {
            int i = nums[j];
            
            if (i && !c) {
               c = true; res = min(res, d); d = 0; 
            }
            else if (i && c) {
                res = 0; break;
            }
            else if (!i) {
                c = false; d++;
            }
        }
        
        return res >= k;
        
    }
};
