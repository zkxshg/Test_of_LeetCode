// https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// Monotonic Stack

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int len = nums.size(); 

        vector<pair<int, int> > recs; recs.push_back(make_pair(nums[0], 1));
        vector<int> stPos; stPos.push_back(0);
        
        int res = 0;
        for (int i = 1; i < len; i++) {
            int h = nums[i], num = 1, lp = i;
            
            while (!recs.empty() && recs.back().first > h) {
                if (stPos.back() <= k && i - 1 >= k)
                    res = max(res, recs.back().first * (i - stPos.back()));
                num += recs.back().second;
                recs.pop_back(); 
                lp = stPos.back(); stPos.pop_back();
            }
            
            if (recs.empty() || recs.back().first != h) {
                recs.emplace_back(make_pair(h, num)); stPos.push_back(lp);
            }
        }
        //for (auto& p : recs) cout << p.first << "," << p.second << endl; // cout << endl;
        //for (int p : stPos) cout << p << ","; cout << endl;
        for (int j = 0; j < recs.size(); j++) 
            if (stPos[j] <= k)
                res = max(res, recs[j].first * (len - stPos[j]));
        
        return res;
    }
};
