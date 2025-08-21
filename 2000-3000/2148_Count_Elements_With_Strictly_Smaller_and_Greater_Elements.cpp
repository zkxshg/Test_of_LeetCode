// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// array

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int st = 1, en = n - 2;
        
        while (st < en) {
            if (nums[st] != nums[st - 1]) break;
            st++;
        }
            
        while (st < en) {
            if (nums[en] != nums[en + 1]) break;
            en--;
        }
        
        if (st == en) {
            if (st >= n - 1 || nums[st] == nums[st + 1]) return 0;
            if (en <= 0 || nums[en] == nums[en - 1]) return 0;
        }

        return en - st + 1;
    }
};
