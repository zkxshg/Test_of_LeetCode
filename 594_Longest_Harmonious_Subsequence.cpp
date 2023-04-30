// hash map
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxV = *max_element(nums.begin(),nums.end());
        int minV = *min_element(nums.begin(),nums.end());
        
        unordered_map<int, int> fre;
        for (int i : nums) fre[i]++;
        
        int res = 0;
        for (int i : nums)
            if (fre[i] && fre[i + 1]) 
                res = max(res, fre[i] + fre[i + 1]);
        
        return res;
    }
};
