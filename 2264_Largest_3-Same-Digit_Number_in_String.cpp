// https://leetcode.com/problems/largest-3-same-digit-number-in-string/?envType=daily-question&envId=2023-12-04
// Rolling Hash

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

    unsigned hash(const string& s) {
        long long ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ret = ret*PRIME_BASE + s[i];
            ret %= PRIME_MOD;
        }
        return ret;
    }

    string largestGoodInteger(string num) {
        unordered_map<ll, int> sco;
        sco[hash("000")] = 0;
        sco[hash("111")] = 111;
        sco[hash("222")] = 222;
        sco[hash("333")] = 333;
        sco[hash("444")] = 444;
        sco[hash("555")] = 555;
        sco[hash("666")] = 666;
        sco[hash("777")] = 777;
        sco[hash("888")] = 888;
        sco[hash("999")] = 999;

        string reStr = ""; int maxSco = -1, n = num.size();

        ll hs0 = hash(num.substr(0, 3));
        if (sco.find(hs0) != sco.end()) {
            reStr = num.substr(0, 3); maxSco = sco[hs0];
        }

        ll ppow = qpow(PRIME_BASE, 3);
        for (int i = 3; i < n; i++) {
            hs0 = hs0 * PRIME_BASE + num[i];
            hs0 %= PRIME_MOD;

            hs0 -= ppow * num[i - 3] % PRIME_MOD; 
            if (hs0 < 0) hs0 += PRIME_MOD;

            if (sco.find(hs0) != sco.end() && sco[hs0] > maxSco) {
                reStr = num.substr(i - 2, 3); maxSco = sco[hs0];
            }
        }

        return reStr;
    }
};
