// hash map + Multiply large numbers
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<long, int> fre;
        for (int i : deliciousness) fre[i]++;
        
        vector<int> deli;
        for (auto& v : fre) deli.emplace_back(v.first);
        
        long long len = deli.size();
        long long res = 0;
        long long up = pow(10, 9) + 7; 
        
        long long maxDeli = *max_element(deli.begin(), deli.end()) % up;
        
        sort(deli.begin(), deli.end());

        for (int i = 0; i < len; i++) {
            long a = deli[i] % up;
            
            if (fre[a] > 1 && if2p(a + a)) {
                if (fre[a] & 1) res += qmul(fre[a], (fre[a] - 1) / 2, up);
                else res += qmul(fre[a] / 2, fre[a] - 1, up);
            } 

            long ub = log(a + maxDeli) / log(2), lb = 0;
            if (a > 0) lb = log(a + a) / log(2) + 1;
            
            for (int j = lb; j <= ub; j++) {
                if (fre[pow(2, j) - a]) {
                    long b = pow(2, j) - a;
                    
                    res += qmul(fre[a], fre[b], up);
                }
            }
            
            res %= up;
        }
        return res;
    }
    
    bool if2p(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
    
    long long qmul(long long x, long long y, long long mod) {
        long long ret = 0;
        while(y) {
            if(y & 1) ret = (ret + x) % mod;
            x = x * 2 % mod;
            y >>= 1;
        }
        return ret;
    }
    
};
