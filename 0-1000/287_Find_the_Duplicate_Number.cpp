// O(n2) brute force
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n1 = nums.size();
        int res = 0;
        int cou = 0;
        for (int i = 1; i < n1; i++){
            cou = 0;
            for (int j = 0; j < n1; j++){
                if (nums[j] == i) cou++;
            }
            if (cou > 1) {
                res = i;
                break;
            }
        }
        return res;
    }
};
