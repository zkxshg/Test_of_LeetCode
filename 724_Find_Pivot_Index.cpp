class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len - 1;
        unordered_map<int, int> sumDict;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            sumDict[i] = sum;
        }
        if (sumDict[len - 1] == sumDict[0]) return 0;
        for (int i = 1; i < len; i++) {
            if ((sumDict[len - 1] - sumDict[i]) == sumDict[i - 1]) return i;
        }
        return -1;
    }
};
