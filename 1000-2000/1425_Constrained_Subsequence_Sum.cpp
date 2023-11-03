// https://leetcode.com/problems/constrained-subsequence-sum/description/
// heap + hash table + dp

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        int res = nums[0];
        
        vector<int> hp; hp.push_back(nums[0]);
        make_heap(hp.begin(), hp.end());
        
        unordered_map<int, int> fre; fre[nums[0]]++;

        for (int i = 1; i < n; i++) {
            int tmp = nums[i];

            if (hp.front() > 0) tmp += hp.front();

            if (hp.size() >= k) {
                fre[nums[i - k]]--;

                while (!hp.empty() && fre[hp.front()] < 1) {
                    pop_heap(hp.begin(), hp.end()); hp.pop_back();
                }
            }

            hp.push_back(tmp); push_heap(hp.begin(), hp.end());
            fre[tmp]++;

            // cout << tmp << ",";

            nums[i] = tmp;
            res = max(res, tmp);
        }

        return res;
        
    }
};
