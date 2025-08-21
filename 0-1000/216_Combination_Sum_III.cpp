// same to 40. Combination Sum II
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (n < 6) return result;
        
        vector<int> candi;
        for (int i = 1; i < 10; i++) candi.push_back(i);
        
        vector<vector<int>> temRes = combinationSum2(candi, n);
        
        for (vector<int> tem : temRes) {
            if (tem.size() == k) result.push_back(tem);
        }
        
        return result;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            
            findSum(candidates, i-1, target - candidates[i], result, temp);
        }
        if (result.size() == 0) return result;
        
        int pos = 0;
        while(pos < result.size() - 1){
            if (find(result.begin() + pos + 1, result.end(), result[pos]) != result.end())
                result.erase(result.begin() + pos);
            else pos++;
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
                 
                 findSum(candidates, i-1, target - candidates[i], result, temp2);
             }
             
         }     
     }
};
