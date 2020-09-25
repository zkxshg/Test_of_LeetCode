// sort 
class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        int len = nums.size(); 
        if (len == 0) return "";
        if (len == 1) return to_string(nums[0]);
        
        string * strs = new string[len];
        for (int i = 0; i < len; i++) strs[i] = to_string(nums[i]);
        
        sort(strs, strs+len, cmp);
        
        string result = "";
        for (int i = 0; i < len; i++) result += strs[i];
        
        while (result.size() > 1 && result[0] == '0') result.erase(0, 1);
        
        return result;  
    }
};
