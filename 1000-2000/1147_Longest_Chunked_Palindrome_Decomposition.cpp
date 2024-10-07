// https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
// rolling hash + greedy

class Solution {
public:
    #define ll long long
    const unsigned PRIME_BASE = 257;
    const unsigned PRIME_MOD = 1000000007;
    
    // 快速幂
    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % PRIME_MOD;
            a = a * a % PRIME_MOD;
            b >>= 1;
        }
        return res;
    }
    
    unsigned hash(const string& s)
    {
        long long ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ret = ret*PRIME_BASE + s[i];
            ret %= PRIME_MOD;
        }
        return ret;
    }
    
    int longestDecomposition(string text) {
        int n = text.size();
        if (n < 2) return 1;
        
        vector<int> dp(n);
        
        ll hash1 = 0;
        ll hash2 = 0;
        int len = 0, res = 0;
        for (int i = 0; i < n / 2; i++) {
            // (i-1)->i
            hash1 = hash1 * PRIME_BASE + text[i];
            hash1 %= PRIME_MOD;
            
            // n-i-1 <- n-i 
            hash2 += text[n - 1 - i] * qpow(PRIME_BASE, len); 
            hash2 %= PRIME_MOD;
            
            // get split -> initial
            if (hash1 == hash2) {
                res += 2;
                hash1 = 0; hash2 = 0; len = 0;
            }
            else len++;
        }
        if (n % 2 || hash1 > 0) res++;
        
        return res;
    }
};
