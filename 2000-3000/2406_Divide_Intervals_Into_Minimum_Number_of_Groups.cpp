// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/?envType=daily-question&envId=2024-10-12
// Greedy + Heap

class Solution {
public:
    static bool cmp(int x,int y) {
        return x>y;
    }

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> hp;
        make_heap(hp.begin(), hp.end(), cmp); 

        for (auto& v : intervals) {
            int l = v[0], r = v[1];

            if (!hp.empty() && l > hp.front()) {
                pop_heap(hp.begin(), hp.end(), cmp); 
                hp.pop_back();
            }

            hp.push_back(r);
            push_heap(hp.begin(), hp.end(), cmp);
        }

        return hp.size();
    }
};
