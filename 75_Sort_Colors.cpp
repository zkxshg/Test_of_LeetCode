// A rather straight forward solution is a two-pass algorithm using counting sort:
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

// two pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size(), pos = 0; 
        bool no0 = false, no1 = false, no2 = false;
        while (pos < len) {
            if (no1) break;
            
            if (!no0) {
                if (nums[pos] == 0) pos++;
                else {
                    for (int i = pos + 1; i < len; i++) {
                        if (nums[i] == 0) {
                            nums[i] = nums[pos];
                            nums[pos] = 0;
                            break;
                        }
                    }
                    if (nums[pos] != 0) no0 = true;
                }
            }
            else {
                if (nums[pos] == 1) pos++;
                else {
                    for (int i = pos + 1; i < len; i++) {
                        if (nums[i] == 1) {
                            nums[i] = nums[pos];
                            nums[pos] = 1;
                            break;
                        }
                    }
                    if (nums[pos] != 1) no1 = true;
                }
            }
        }
    }
};
