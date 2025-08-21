// https://leetcode.com/problems/count-nice-pairs-in-an-array/
// hash table + math

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;
    
    int reverse(int a) {
        int res = 0;
        while (a) {
            res = res * 10 + (a % 10); a /= 10;
        }
        return res;
    }
    
    ll qmul(ll x, ll y) {
        ll ret = 0;
        while (y) {
            if (y & 1)
                ret = (ret + x) % ub;
            x = x * 2 % ub;
            y >>= 1;
        }
        return ret; // x * y
    }
    
    int countNicePairs(vector<int>& nums) {
        // for (int i : nums) cout << i << ":" << reverse(i) << endl;
        unordered_map<int, int> diffSet;
        
        for (int i : nums) diffSet[i - reverse(i)]++;
        
        long long res = 0;
        for (auto& p : diffSet) {
            if (p.second > 1) {
                int a = p.second % 2 ? p.second : p.second / 2;
                int b = p.second % 2 ? (p.second - 1) / 2 : p.second - 1;
                res = (res + qmul(a, b)) % ub;
            }
        }
        
        return res;
    }
};
