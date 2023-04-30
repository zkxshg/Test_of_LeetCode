// Backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len == 1) {
            result.push_back(vector<int>(1, nums[0]));
            return result;
        }
        for (int i = 0; i < len; i++){
            vector<int> excep = nums;
            excep.erase(excep.begin()+i);
            vector<vector<int>> temres = permute(excep);
            for (int j = 0; j < temres.size(); j++){
                vector<int> temp = temres[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
