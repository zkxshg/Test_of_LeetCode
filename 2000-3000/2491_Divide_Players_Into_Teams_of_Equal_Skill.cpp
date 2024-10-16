// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/?envType=daily-question&envId=2024-10-04
// Sorting

class Solution {
public:
    #define ll long long

    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        ll res = 0;
        int tt = skill[0] + skill[n - 1];

        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - 1 - i] != tt) return -1;
            res += skill[i] * skill[n - 1 - i];
        }

        return res;
    }
};
