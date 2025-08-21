// stack
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size(); if (len < 3) return false;
        
        vector<int> st;
        int sec = INT_MIN;
        
        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] < sec) return true;
            
            while (!st.empty() && nums[i] > st.back()) {
                sec = st.back();
                st.pop_back();
            }
            
            st.push_back(nums[i]);
        }
        
        return false;
    }
};
