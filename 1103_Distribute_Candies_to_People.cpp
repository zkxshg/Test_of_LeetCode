// https://leetcode.com/problems/distribute-candies-to-people/
// math

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int nc = candies, np = num_people;
        
        int round = 0, a1 = 1, left = nc;
        while (left > 0) {
            left -= np * (a1 + a1 + np - 1) / 2;
            round++; a1 += np;
        }
        
        vector<int> res(np);
        for (int i = 0; i < np; i++) 
            res[i] += (i + 1) * (round - 1) + (round - 1) * (round - 2) * np / 2;
        
        left = nc; a1 = 1; // cout << "round = " << round << endl;
        for (int i = 0; i < np; i++) left -= res[i];
        
        int nex = a1 + (round - 1) * np;
        for (int i = 0; i < np; i++) {
            if (left <= nex) {
                res[i] += left; break;
            }
            else {
                res[i] += nex; left -= nex; nex++;
            }
        }
        
        return res;
    }
};
