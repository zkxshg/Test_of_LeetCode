// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
// Greedy

class Solution {
public:
    #define ll long long
    long long minimumReplacement(vector<int>& v) {
        ll ans = 0;

        ll maxMin = v[v.size() - 1];
        for (int i = v.size() - 2; i >= 0; i--) {
            if (v[i] > maxMin) {
                int partition = ceil(v[i] / double(maxMin));
                ans += partition - 1;
                maxMin = v[i] / partition;
            }
            else {
                maxMin = v[i];
            }
        }
        
        return ans;
    }
};
