# https://leetcode.com/problems/super-ugly-number/
# heap

class Solution {
public:
    #define Ull unsigned long long
    #define ll long long
    #define UB UINT_MAX
    
    static bool cmp(int x, int y) {
        return x>y;
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        
        vector<ll> hp; hp.push_back(1);    
        make_heap(hp.begin(), hp.end(), cmp);
        
        int cou = 0;
        
        while (cou < n) {
            ll tp = hp.front(); cou++;
            // cout << tp << ":" << cou << endl;
            
            if (cou >= n) return (unsigned int)tp;
            
            pop_heap(hp.begin(), hp.end(), cmp); hp.pop_back();
            
            for (ll p : primes) {
                ll nex = p * tp; 
                if (nex > INT_MAX) break;
                hp.push_back(nex); push_heap(hp.begin(), hp.end(), cmp);
            }
            
            while (hp.front() == tp) {
                pop_heap(hp.begin(), hp.end(), cmp); hp.pop_back();
            }
            
        } 
        
        return hp.front();
    }
};
