// https://leetcode.com/problems/fruit-into-baskets/description/
// sliding window

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> fre;

        int res = 1, fres = 1, pack = 1;

        int st = 0, en = 1; fre[fruits[0]]++;
        while (en < n) {
            int f = fruits[en];

            if (fre[f] > 0) {
                res++; fre[f]++;
                fres = max(res, fres);
            }
            else {
                if (pack < 2) {
                    pack++; fre[f]++; res++;
                    fres = max(res, fres);
                }
                else {
                    while (pack >= 2 && st < en) {
                        int pf = fruits[st];

                        fre[pf]--; res--;
                        if (fre[pf] <= 0) pack--;

                        st++;
                    }

                    pack++; fre[f]++; res++;
                    fres = max(res, fres);
                }

            }

            en++;
        }

        return fres;
    }
};
