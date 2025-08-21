// DP
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return nums;
        
        sort(nums.begin(), nums.end());
        
        bool one = true;
        if (nums[0] != 1) {
            nums.insert(nums.begin(), 1);
            one = false;
            len++;
        }

        vector<int> acc(len, 0);
        vector<int> nex(len, 0);
        
        for (int i = len - 1; i >= 0; i--) {
            nex[i] = i;
            for (int j = i + 1; j < len; j++) {
                if (nums[j] % nums[i] == 0 && acc[j] > acc[i]) {
                    acc[i] = acc[j];
                    nex[i] = j;
                }
            }
            acc[i]++;
        }
        
        vector<int> result;
        
        int pos = 0;
        while (nex[pos] != pos) {
            result.push_back(nums[pos]);
            pos = nex[pos];
        }
        result.push_back(nums[pos]);
        
        if (!one) result.erase(result.begin());
        
        return result;
    }
};
