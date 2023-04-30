// https://leetcode.com/problems/decode-ways/
// DP

class Solution {
public:
    
    #define ll long long

ll qmul(ll x, ll y, ll mod)
{
    ll ret = 0;
    while (y) {
        if (y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
}
    
    int numDecodings(string s) {
        int n = s.size();
        
        vector<ll> nums(n + 1); 
        nums[n] = 1; 
        
        nums[n - 1] = (s[n - 1] == '0') ? 0 : 1;
         
        //ll ub = 1e9 + 7;
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') {
                nums[i] = 0; continue;
            }
            
            int single = (s[i] == '0') ? 0 : 1;
            
            int bi = 1;
            
            if (s[i] >= '3' && s[i] <= '9') bi = 0;
            else if (s[i] == '2' && s[i + 1] >= '7' ) bi = 0;
            
            nums[i] = (single * nums[i + 1]) + (bi * nums[i + 2]);
        }
        
        // for (int i = 0; i <= n; i++) cout << nums[i] <<","; cout << endl;        
        return nums[0];
    }
};
