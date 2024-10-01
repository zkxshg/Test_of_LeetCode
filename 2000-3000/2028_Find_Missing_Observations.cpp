// https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-01
// Math + size() -> UnsignedInt error

class Solution {
public:

    int checkNum(vector<int>& res, int num, int nsum, int n) {
        while  (nsum - num >= 0 && (nsum - num >= n - res.size() - 1)) {
            //cout << nsum - num << endl;
            //cout << (n - res.size() - 1) << endl;
            // int s = res.size();
            //cout << (nsum - num) - (n - s - 1) << endl;

            //if ((nsum - num) >= (n - res.size() - 1)) cout << "True" << endl;
            //else cout << "False" << endl;

            res.push_back(num);
            nsum -= num;
        }

        //cout << -3 - 2 << endl;
        return nsum;
    }
    
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int msum = accumulate(rolls.begin(), rolls.end(), 0);
        int nsum = mean * (m + n) - msum;
        if (nsum > n * 6) return {};

        vector<int> res;
        for (int i = 6; i >= 1; i--) nsum = checkNum(res, i, nsum, n);

        return res;
    }
};
