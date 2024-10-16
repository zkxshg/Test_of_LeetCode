// https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14
// Heap

class Solution {
public:
    #define ll long long

    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());

        ll res = 0;
        for (int i = 0; i < k; i++) {
            int top = nums.front();
            pop_heap(nums.begin(), nums.end()); nums.pop_back();

            res += top;
            top = top / 3 + (top % 3 ? 1 : 0);

            nums.push_back(top); 
            push_heap(nums.begin(), nums.end());  
        }

        return res;
    }
};
