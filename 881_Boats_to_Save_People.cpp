// greedy + two pointers
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int num = people.size(); if (num == 1) return 1;
        
        sort(people.begin(), people.end());
        
        int res = 0, st = 0, en = num - 1;
        while (st <= en) {
            int lm = limit;
            lm -= people[en]; en--;
            if (st <= en && people[st] <= lm) st++;
            res++;
        }
        
        return res;
    }
};
