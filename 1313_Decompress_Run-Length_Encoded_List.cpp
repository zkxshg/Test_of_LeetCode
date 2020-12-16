// array
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result; int len = nums.size();
        for (int i = 0; i < len; i+=2) {
            int num = nums[i + 1], fre = nums[i];
            for (int j = 0; j < fre; j++) result.emplace_back(num);
        }
        return result;
    }
};
