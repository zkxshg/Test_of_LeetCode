// hash map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> fre;
        for (int i : nums) fre[i]++;
        
        int res = 0;
        for (int i : nums) {
            if (fre[i] > 0) {
                int x = i;
                int k_x = k - x;
                if (!fre[k_x]) continue;
                
                if (x != k_x) {
                    res += min(fre[i], fre[k_x]);
                    fre[x] = 0; fre[k_x] = 0;
                }
                else {
                    res += (fre[i] / 2);
                    fre[x] = 0;
                }  
            }
        }
        
        return res;
    }
};
