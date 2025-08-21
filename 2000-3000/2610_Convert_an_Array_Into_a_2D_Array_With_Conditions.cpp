// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
// Hash table

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();

        vector<int> fre(n + 1);
        for (int i : nums) fre[i]++;

        int row_num = *max_element(fre.begin(), fre.end());
       
        vector<vector<int> > res(row_num);
        vector<int> fre2(n + 1);
        
        for (int i : nums) res[fre2[i]++].push_back(i);
        return res;
    }
};
