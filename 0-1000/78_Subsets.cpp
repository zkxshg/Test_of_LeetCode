// bit maniputation
// cou = [0, 2^len]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        int resNum = pow(2, len);
        int cou = 0;
        for (int i = 0; i < resNum; i++) {
            vector<int> temp;
            bitset<32> bits(cou);
            for (int j = 0; j < len; j++) {
                if (bits[j]) temp.push_back(nums[j]);
            }
            result.push_back(temp);
            cou++;
        }
        return result;
    }
};
