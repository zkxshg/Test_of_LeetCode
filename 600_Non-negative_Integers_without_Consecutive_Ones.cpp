// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// DP + math

class Solution {
public:
    #define ll long long
    
    int findIntegers(int n) {
        ll res = 0;
        
        int lv = 0;
        while (n >= pow(2, lv)) lv++;
        
        bitset<32> bi(n); 
        // cout << lv <<":" << n << ":" << bi << endl;
        
        vector<pair<int, int> > num;  
        num.push_back(make_pair(1, 1)); 
        
        for (int i = 1; i < lv; i++) {
            int f = num.back().first + num.back().second;
            int s = num.back().first;
            
            num.push_back(make_pair(f, s)); 
        }
        
        // for (auto& p : num) cout << p.first << ":" << p.second << ","; cout << endl;
        
        res += num.back().first; res += num.back().second;
        
        if (!bi[lv - 2]) {
             for (int i = lv - 3; i >= 0; i--) {
                 if (!bi[i] && !bi[i + 1]) res -= num[i].second;
                 else if (bi[i] && bi[i + 1]) break; 
            }
        }
          
        return res;
    }
};
