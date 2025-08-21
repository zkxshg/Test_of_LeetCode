// DP
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        if (arr.size() < 2) return 1;
        sort(arr.begin(), arr.end());
        
        unordered_map<int, int> fre;
        for (int i : arr) fre[i]++;

        long long res = 0, top = 1e9 + 7;
        for (long long i : arr) {
            for (long long j : arr) {
                if (j >= i) break;
                
                long long k = i / j;
                
                if (fre[k] && k * j == i) fre[i] += qmul(fre[j], fre[k], top);
                fre[i] %= top;
                //cout << "i = " << i << ", j = " << j << ", k = " << k <<endl;
            }
            res += fre[i]; res %= top;
        }
        return res;
    }
    
    long long qmul(long long x, long long y, long long mod)  {
        long long ret = 0;
        while(y) {
            if(y & 1)
                ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }
    
};
