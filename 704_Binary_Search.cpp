// Binary_Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 1) return -1;
        if (len < 2) {
            if (nums[0] == target) return 0;
            return -1;
        }
        
        return biSearch(nums, target, 0, len - 1);
    }
    
    int biSearch(vector<int>& nums, int tar, int st, int la) {
        if (st == la) {
            if (nums[st] == tar) return st;
            return -1;
        }
        
        int mid = (st + la) / 2;
        
        if (nums[mid] == tar) return mid;
        else if (nums[mid] > tar) return biSearch(nums, tar, st, mid);
        return biSearch(nums, tar, mid + 1, la);    
    }
    

};
