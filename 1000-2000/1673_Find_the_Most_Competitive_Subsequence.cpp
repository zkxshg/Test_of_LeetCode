// stack
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (k == 1) return {*min_element(nums.begin(),nums.end())};
        
        int len = nums.size(); 
        if (len == 1) return {nums[0]};
        if (len == k) return nums;
        
        if (min_element(nums.begin(), nums.end()) == max_element(nums.begin(), nums.end())) {
            vector<int> same = vector<int>(nums.begin(), nums.begin() + k);
            return same;
        }        
        
        vector<int> res;
        res.push_back(nums[0]);
        
        for (int i = 1; i < len; i++) {
            if (nums[i] < res.back() || (len - 1 - i) <= (k - res.size())) {
                while (!res.empty() && nums[i] < res.back() && (len - 1 - i) >= (k - res.size())) res.pop_back();
                if (res.size() < k) res.push_back(nums[i]);
            }
            else if (res.size() < k) res.push_back(nums[i]);
        }
        
        vector<int> result(res.begin(), res.begin() + k);
        return res;  
    }
};

// two points
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (k == 1) return {*min_element(nums.begin(),nums.end())};
        
        int len = nums.size(); 
        if (len == 1) return {nums[0]};
        if (len == k) return nums;
        
        if (min_element(nums.begin(), nums.end()) == max_element(nums.begin(), nums.end())) {
            vector<int> same = vector<int>(nums.begin(), nums.begin() + k);
            return same;
        }        
        vector<int> res;
        
        int pos = 0;
        while (k > 0) {
            int UB = len - k + 1;
            int temp = min_element(nums.begin() + pos, nums.begin() + UB) - nums.begin();
            res.push_back(nums[temp]);
            pos = temp + 1;
            k--;
        }
        
        return res;  
    }
};
