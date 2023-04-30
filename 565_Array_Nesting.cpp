// https://leetcode.com/problems/array-nesting/
// DFS

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> fre;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a = nums[i], tem = 0;
            while (!fre[a]) {
                tem++; fre[a] = 1;
                a = nums[a];
            }
            res = max(res, tem);
        }
        
        return res;
    }
};
