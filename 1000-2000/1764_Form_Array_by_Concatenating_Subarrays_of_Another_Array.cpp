// Greedy + Two pointers: O(n)
// (Faster with KMP)
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int pos = 0, len = nums.size(), num = groups.size(); 
        
        for (int i = 0; i < num; i++) {
            vector<int> g = groups[i];
            int n = g.size();
            
            if (i < num - 1 && pos + n >= len) return false;
            
            bool get = false;
            
            while (pos <= len - n) {
                int tem = 0;
                
                while (tem < n) {
                    if (nums[pos + tem] == g[tem]) tem++;
                    else break;
                }
                
                if (tem == n) {
                    pos += tem;
                    get = true;
                    break; 
                }
                else pos++;
            }
            
            if (!get) return false;
        }
        
        return true;
    }
};
