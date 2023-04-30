// two pointers
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        int len = nums.size();
        
        if (len == 0) return result;
        
        if (len == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }
        
        int start = nums[0], tail = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i] == nums[i - 1] + 1) tail = nums[i];
            else {
                if (tail > start) {
                    string ranges = to_string(start);
                    ranges += "->";
                    ranges += to_string(tail);
                    result.push_back(ranges);
                }
                else result.push_back(to_string(start));
                
                start = nums[i];
                tail = start;
            }
        }
        
        if (tail > start) {
            string ranges = to_string(start);
            ranges += "->";
            ranges += to_string(tail);
            result.push_back(ranges);
        }
        else result.push_back(to_string(start));
        
        return result;
    }
};
