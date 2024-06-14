// https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14
// greedy

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> fre;
        vector<int> dup;
        for (int i = n - 1; i >= 0; i--) {
            if (fre.count(nums[i]) != 0) dup.push_back(nums[i]);
            fre[nums[i]]++;
        }
            
        int res = 0, st = nums[0] + 1;
        while (!dup.empty()) {
            if (fre.count(st) == 0) {
                if (dup.back() < st) { 
                    // cout << st << "-" << dup.back() << "=" << st - dup.back() << endl;
                    res += st - dup.back();
                    dup.pop_back();
                    
                }
            }

            st++;
        }

        return res;
    }
}; 
