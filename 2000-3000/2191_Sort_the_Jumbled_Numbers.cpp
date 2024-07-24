// https://leetcode.com/problems/sort-the-jumbled-numbers/submissions/1332157788/?envType=daily-question&envId=2024-07-24
// Sorting

class Solution {
public:
    #define pii pair<int, int>

    int mapNum(vector<int>& mapping, int num){
        vector<int> mapped;
        if (num == 0) mapped.push_back(num);
        while (num) {
            mapped.push_back(num % 10);
            num /= 10;
        }

        int res = 0;
        while (!mapped.empty()) {
            res = res*10 + mapping[mapped.back()];
            mapped.pop_back();
        }

        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pii> freArr;
        for (int i = 0; i < n; i++) {
            int mpdNum = mapNum(mapping, nums[i]);
            freArr.push_back({mpdNum, i});
            cout << mpdNum << endl;
        }

        sort(freArr.begin(), freArr.end(), [](const pii& a, const pii& b) {
            if (a.first == b.first) return a.second < b.second; 
            else return a.first < b.first;
        });
 
        vector<int> res;
        for (auto& p : freArr) res.push_back(nums[p.second]);
        return res;
    }
};
