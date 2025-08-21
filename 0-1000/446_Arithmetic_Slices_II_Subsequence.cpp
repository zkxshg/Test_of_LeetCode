class Solution {
public:
    // 阶乘
    int factorial(int n) {
        int fc = 1;
        for (int i = 1; i <= n; ++i) fc *= i;
        return fc;
    }

    // 组合数
    int combo(int n, int m) {
        if (m == 0 || m == n) return 1;
        int com = factorial(n) / (factorial(m) * factorial(n - m));
        return com;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());

        int res = 0;
        
        vector<set<int>> divs(n);
        
        for (int i = n - 1; i > 0; i--) 
            for (int j = i - 1; j >= 0; j--)
                divs[i].insert(nums[i] - nums[j]);
        
        for (auto& v : divs) {
            for (int i : v) cout << i << ","; cout << endl;
        }
        
        unordered_map<int, int> got;
        
        for (int i = 1; i < n - 1; i++) {
            for (int d : divs[i]) {
                if (!got[d]) {
                    int fre = 1;
                    
                    for (int j = i + 1; j < n; j++)
                        if (divs[j].count(d))
                            fre++;
                    
                    // if (fre > 1) res += pow(2, res) ;
                    cout << d << ":" << fre << endl;
                    got[d] = 1;
                }
            }
        }
        
        return res;
    }
};
