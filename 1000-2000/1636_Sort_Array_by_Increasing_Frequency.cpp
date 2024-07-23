// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
// Sorting + Stack (RLE) (8min)

class Solution {
public:
    #define pii pair<int, int>
    vector<int> frequencySort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<pii> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (st.empty() || st.back().second != nums[i]) st.push_back({1, nums[i]});
            else st.back().first++;
        }

        sort(st.begin(), st.end(), [](const pii& a, const pii& b) {
            if (a.first == b.first) return a.second < b.second;
            else return a.first > b.first;
        });

        vector<int> result;
        while (!st.empty()) {
            int frequency = st.back().first;
            int number = st.back().second;
            st.pop_back();
            while (frequency-- > 0) {
                result.push_back(number);
            }
        }
        
        return result;
    }
};
