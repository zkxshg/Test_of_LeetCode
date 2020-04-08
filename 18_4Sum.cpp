// // same to 15. 3Sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        if (nums.size() < 4) return sol;
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < nums.size() - 1; i++){
            if (i == 0 || nums[i] != nums[i-1]){
                vector<int> temp;
                temp.push_back(nums[i]);
                vector<int> temnum(nums.begin() + i + 1, nums.end());
                threeSum(temnum, sol, temp, target - nums[i]);
            }
        }
        
        return sol;
        
    }
    
   void threeSum(vector<int>& nums, vector<vector<int>> & sol, vector<int> & temp, int target) {
        if (nums.size() >= 3) {
            for (int i = 0; i < nums.size() - 1; i++){
                if (i == 0 || nums[i] != nums[i-1]){
                    vector temp2 = temp;
                    temp2.push_back(nums[i]);
                    vector<int> temnum(nums.begin() + i + 1, nums.end());
                    xSum(temnum, sol, temp2, target - nums[i]);
                }
            }  
        }
    }
    
    void xSum(vector<int>& nums, vector<vector<int>>& sol, vector<int> & temp, int target){
        if (nums.size() >= 2) {
            int left = 0;
            int right = nums.size() - 1;
            
            while(left < right){
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    vector<int> temp2 = temp;
                    temp2.push_back(nums[left]);
                    temp2.push_back(nums[right]);
                    sol.push_back(temp2);
                    
                    while(left + 1 < nums.size() && nums[left] == nums[left+1]) left++;
                    while(right > 0 && nums[right] == nums[right-1]) right--;
                    if (left >= right) break;
                    
                    vector<int> temnum(nums.begin()+left+1, nums.begin()+right);
                    xSum(temnum, sol, temp, target);
                    break;
                }
                else if (sum < target) left++;
                else right--;
            }  
        } 
    }
};
