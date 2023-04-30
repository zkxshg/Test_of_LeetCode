// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// binary search
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int len = nums.size();
        
        int LB = 0;
        for (int i : nums) LB += i / threshold;
        LB = max(1, LB);
        
        int UB = 0;
        double th = max(1, threshold - len);
        for (int i : nums) UB += ceil(i / th);
        
        /* int res = 1;
        for (int i = LB; i <= UB; i++) {
            if (meeTH(nums, threshold, i)) {
                res = i;
                break;
            }
        }*/
        
        int res = bi(nums, threshold, LB, UB);
        return res;
    }
    
    int bi(vector<int>& nums, int threshold, int lb, int rb) {
        if (lb == rb) return lb;
        
        int mid = (lb + rb) / 2;
        
        if (meeTH(nums, threshold, mid)) {
            if (mid == 1 || !meeTH(nums, threshold, mid - 1)) return mid;
            else return bi(nums, threshold, lb, mid);
        }
        else return bi(nums, threshold, mid, rb);
    }
    
    bool meeTH(vector<int>& nums, int threshold, int aim) {
        double th = aim;
        int res = 0;
        for (int i : nums) res += ceil(i / th);
        return res <= threshold;
    }
};
