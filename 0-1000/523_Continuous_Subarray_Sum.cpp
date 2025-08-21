// sane to 560. Subarray Sum Equals K
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 2) return false;
        
        unordered_map<int, int> sumDict;
        int sum = 0;
        
        if (k == 0) {
            for (int i = 1; i < len; i++) {
                if (!nums[i] && !nums[i - 1]) return true;
            }
        }
        else {
            for (int i = 0; i < len; i++) {
                if (i > 1 && !nums[i] && !nums[i - 1]) return true;
                sum += nums[i];
                if (!(sum % k) && i > 0) return true;
                if (sumDict[sum % k] && (nums[i] % k)) return true;
                sumDict[sum % k]++;
            }
        }
        return false;
    }
};
