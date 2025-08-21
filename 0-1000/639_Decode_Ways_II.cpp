// https://leetcode.com/problems/decode-ways-ii/
// DP + Exausted

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
        
        nums[n - 1] = (s[n - 1] == '*') ? 9 : 1;
        if (s[n - 1] == '0') nums[n - 1] = 0;
         
        ll ub = 1e9 + 7;
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') {
                nums[i] = 0; continue;
            }
            
            int single = (s[i] == '*') ? 9 : 1;
            if (s[i + 1] == '0') single = 0;
            
            int bi = 1;
            
            if (s[i] >= '3' && s[i] <= '9') bi = 0;
            else if (s[i + 1] == '*') {
                if (s[i] == '1') bi = 9;
                else if (s[i] == '2') bi = 6;
                else if (s[i] == '*') bi = 15;
            }
            else if (s[i] == '*') {
                if (s[i + 1] <= '6') bi = 2;
                else bi = 1;
            }
            else if (s[i] == '2' && s[i + 1] >= '7' ) bi = 0;
            
            nums[i] = qmul(single, nums[i + 1], ub) + qmul(bi, nums[i + 2], ub);
            nums[i] %= ub;
        }
        
        for (int i = 0; i <= n; i++) cout << nums[i] <<","; cout << endl;        
        return nums[0] % ub;
    }
};
