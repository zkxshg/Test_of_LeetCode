// same to 46_Permutations.cpp + dict
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        
        if (len == 0) return result;
        
        if (len == 1) {
            result.push_back(vector<int>(1, nums[0]));
            return result;
        }
        
        vector<int> rec(1000, -1);
        vector<int> negrec(1000, -1);
        
        for (int i = 0; i < len; i++){
            if (nums[i] < 0){
                if (negrec[-nums[i]] > 0) continue;
                else negrec[-nums[i]] = 1;
            }
            else{
                if (rec[nums[i]] > 0) continue;
                else rec[nums[i]] = 1;
            }
            
            vector<int> excep = nums;
            excep.erase(excep.begin()+i);
            vector<vector<int>> temres = permuteUnique(excep);
            
            for (int j = 0; j < temres.size(); j++){
                vector<int> temp = temres[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
        
    }
};
