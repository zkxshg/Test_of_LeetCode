// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
// Binary search

class Solution {
public:
    #define ll long long
    #define sp spells
    #define po potions

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = sp.size(), m = po.size();

        vector<double> pos(m);
        for (int i = 0; i < m; i++) pos[i] =  success / (double)po[i];

        sort(pos.begin(), pos.end());

        // for (int i = 0; i < m; i++) cout << pos[i] << ","; cout << endl;

        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[i] = upper_bound(pos.begin(), pos.end(), sp[i]) - pos.begin();
        
        return res;
    }
};
