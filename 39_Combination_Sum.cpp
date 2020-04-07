// backtracing
// findSum(candidates, i, target - candidates[i], result, temp);
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int len = candidates.size();
        if (len == 0) return result;
        
        sort(candidates.begin(), candidates.end());
        
        for (int i = candidates.size() - 1; i >= 0; i--){
            if (candidates[i] > target) continue;
            
            vector<int> temp;
            temp.push_back(candidates[i]);
            
            if (candidates[i] == target){
                result.push_back(temp);
                continue;
            }
            
            findSum(candidates, i, target - candidates[i], result, temp);
        }
        return result;
    }
    
    void findSum(vector<int>& candidates, int limit, int target, vector<vector<int>>& result, vector<int> temp){
         if (candidates[0] <= target){
             
             for (int i = limit; i >= 0; i--){
                 if (candidates[i] > target) continue;
                 
                 vector<int> temp2 = temp;
                 temp2.push_back(candidates[i]);
                 if (candidates[i] == target){
                     result.push_back(temp2);
                     continue;
                 }
                 
                 findSum(candidates, i, target - candidates[i], result, temp2);
             }
             
         }     
     }
          
};
