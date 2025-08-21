// https://leetcode.com/problems/rabbits-in-forest/
// greedy

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        
        vector<int> rab(1001);
        for (int i : answers) rab[i]++;
        
        int res = 0;
        for (int i = 0; i <= 1000; i++) {
            if (rab[i]) res += ceil((double)rab[i]/(i + 1)) * (i + 1);
        }
        
        return res;
        
    }
};
