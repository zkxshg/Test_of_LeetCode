// https://leetcode.com/problems/subarrays-with-k-different-integers/
// Sliding Window
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        int st = 0, en = 0, cou = 1, res = 0;
        unordered_map<int, int> fre; fre[nums[st]]++;
        if (k == 1) res++;
        
        while(en < n) {
            if (cou >= k && st < en) {  
                
                // [st++, en]
                int a = nums[st];
                st++;
                
                fre[a]--;
                if (!fre[a]) cou--;
                
                // [st+, en--]
                if (cou >= k) {
                    if (cou == k) res++; // cout << st << ":" << en << endl;
                    
                    // pre--
                    int pre = en, tem = cou;
                    while (pre >= st && tem >= k) {
                        fre[nums[pre]]--;
                        if (!fre[nums[pre]]) tem--;
                        
                        if (tem == k) res++;
                        pre--;
                    }
                    
                    // Recover
                    for (int i = pre + 1; i <= en; i++) fre[nums[i]]++;
                }
            }
            else {
                // [st, en++]
                en++;
                
                if (en >= n) break;
                
                int a = nums[en];
                if(!fre[a]) cou++;
                fre[a]++;
                
                // [st--, en+]
                if (cou <= k) {
                    if (cou == k) res++; // cout << st << ":" << en << endl;

                    // pre--
                    int pre = st, tem = cou;
                    while (pre > 0 && tem <= k) {
                        pre--;
                        
                        if (!fre[nums[pre]]) tem++;
                        fre[nums[pre]]++;
                        
                        
                        if (tem == k) res++;
                    }
                    
                    // Recover
                    for (int i = pre; i < st; i++) fre[nums[i]]--;  
                }
            }
            
        }
        
        return res;
        
    }
};
