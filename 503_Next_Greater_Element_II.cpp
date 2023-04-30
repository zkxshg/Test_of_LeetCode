// https://leetcode.com/problems/next-greater-element-ii/
// stack

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n, -1);
        
        vector<pair<int, int> > st; st.push_back({nums[0], 0});
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.back().first < nums[i]) {
                res[st.back().second] = nums[i];
                st.pop_back();
            } 
            
            st.push_back({nums[i], i});
        }
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.back().first < nums[i]) {
                res[st.back().second] = nums[i];
                st.pop_back();
            } 
        }
        
        return res;
    }
};
