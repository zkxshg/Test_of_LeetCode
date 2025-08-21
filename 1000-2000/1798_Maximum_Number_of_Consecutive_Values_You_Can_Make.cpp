// greedy
class Solution {
public:
    vector<int> fre;
    
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        
        sort(coins.begin(), coins.end());
        if (coins[0] > 1) return 1;
        
        int res = 0;
        for (int i : coins) {
            if (i <= res + 1) res += i;
            else break;
        }
        
        return res + 1;
    }
    
    bool getSum(vector<int>& c, int pos, int tar) {
        if (tar == 0) return true;
        if (pos < 0 || tar < 0) return false;

        if (c[pos] == tar) return true;
        else if (c[pos] < tar && getSum(c, pos - 1, tar - c[pos]))  return true;

        return getSum(c, pos - 1, tar);
    }
};
