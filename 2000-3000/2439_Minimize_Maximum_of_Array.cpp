// https://leetcode.com/problems/minimize-maximum-of-array/description/
// Binary Search

class Solution {
public:
    #define ll long long
    bool ifMeet(vector<int>& nums, ll aim) {
        bool meet = true;
        ll spa = 0; 
        for (int i : nums) {
            if (i > aim) {
                if (i - spa <= aim) spa -= i - aim;
                else {
                    meet = false; break;
                }
            }
            else spa += aim - i;
        }
        return meet;
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll st = *min_element(nums.begin(), nums.end());
        ll en = *max_element(nums.begin(), nums.end());

        while (st < en) {
            ll mid = (st + en) / 2;

            if (!ifMeet(nums, mid)) st = mid + 1;
            else en = mid;
        }

        return st;
    }
};
