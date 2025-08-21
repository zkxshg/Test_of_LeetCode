// https://leetcode.com/problems/subsets-ii/
// hash map + BFS

class Solution {
public:
    bool ifExist(unordered_map<string, int>& dict, vector<int>& sub) {
        sort(sub.begin(), sub.end());
        
        string s = ""; for (int i : sub) s += ('a' + i + 10);
        
        if (!dict[s]) {
            dict[s] = 1; return true;
        }
        
        return false;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<string, int> dict;
        vector<vector<int>> res; res.push_back({});
        
        vector<vector<int>> bfs; 
        
        for (int i = 0; i < n; i++) {
            vector<int> sub(nums.begin() + i, nums.begin() + i + 1);
            if (ifExist(dict, sub)) {
                res.push_back(sub); bfs.push_back({i});
            }
        }
        
        int iter = 1;
        while (iter < n && !bfs.empty()) {
            vector<vector<int>> tem; 
            
            for (auto& v : bfs) {
                int last = v.back();
                
                for (int j = last + 1; j < n; j++) {
                    vector<int> sub;
                    for (int i : v) sub.push_back(nums[i]);
                    sub.push_back(nums[j]);
                    
                    if (ifExist(dict, sub)) {
                        res.push_back(sub); 
                        
                        vector<int> newV(v.begin(), v.end()); 
                        newV.push_back(j);
                        tem.push_back(newV);
                    }
                }
            }
            bfs = tem;
        }
  
        return res;
    }
};
