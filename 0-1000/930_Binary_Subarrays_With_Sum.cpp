// https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14
// sliding window

class Solution {
public:
    int sigma(int n) {
        return n * (n + 1) / 2;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> pos_1;
        for (int i = 0; i < n; i++) {
            if (nums[i]) pos_1.push_back(i);
        }

        int res = 0, n1 = pos_1.size();

        if (goal == 0) {
            if (pos_1.size() < 1) return sigma(n);

            res += sigma(pos_1[0]);
            for (int i = 1; i < n1; i++) res += sigma(pos_1[i] - pos_1[i - 1] - 1);
            res += sigma(n - 1 - pos_1.back());

            return res;
        }

        if (pos_1.size() < 1) return 0;

        int pre = 0, suf = 0, tmp = 1;
        while (tmp < goal && suf < n1) {
            suf++;
            if (suf < n1) tmp++;
        }

        if (tmp < goal) return 0;

        if (suf < n1 - 1) res += (pos_1[pre] + 1) * (pos_1[suf + 1] - pos_1[suf]);
        else res += (pos_1[pre] + 1) * (n - pos_1[suf]);

        while (suf < n1) {
            pre++; suf++;

            if (suf < n1) {
                res += (pos_1[pre] - pos_1[pre - 1]) * 
                       ((suf < n1 - 1 ? pos_1[suf + 1] : n) - pos_1[suf]);
            }
        }
        
        return res;
    }
};
