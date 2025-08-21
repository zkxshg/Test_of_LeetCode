// store sum frequencies
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0) return 0;
        unordered_map<int, int> sumDict;
        int sum = 0, cou = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (sum == k) cou++;
            if (sumDict[sum - k]) cou += sumDict[sum - k];
            sumDict[sum]++;
        }
        return cou;
    }
};
