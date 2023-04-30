// https://leetcode.com/problems/reverse-pairs/
// Merge sort + binary search

class Solution {
public:
    #define UB INT_MAX/2
    #define LB INT_MIN/2
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> tem(n);
        
        int res = 0;
        for (int seg = 1; seg < n; seg += seg) {
            //cout << "seg = " << seg << endl;
            for (int st = 0; st < n; st += 2 * seg) {
                int low = st, up = min(low + 2 * seg, n);
                int mid = min(low + seg, n);
                
                int st1 = low, ed1 = mid, st2 = mid, ed2 = up;
                //cout << "st1 = " << st1 << ", ed1 = " << ed1 << ", ed2 = " << ed2 << endl;
                
                for (int i = st2; i < ed2; i++) {
                    int aim = 0;
                    
                    if (nums[i] > UB) continue;
                    else if (nums[i] < LB) aim = INT_MIN;
                    else aim = nums[i] * 2;

                    int lb = upper_bound(nums.begin() + st1, nums.begin() + ed1, aim) - nums.begin();
                    //cout << "i = " << i << ", nums[i] = " << nums[i] << ", lb = " << lb << endl;
                    res += ed1 - lb;
                }
                //for (int i = st1; i < ed2; i++) cout << nums[i] << ","; cout << endl;
                sort(nums.begin() + st1, nums.begin() + ed2);
            }
        }
        
        // for (int i : nums) cout << i << ","; cout << endl;
        
        return res;
    }
};
