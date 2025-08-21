// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// heap

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        int x = a.first + a.second, y = b.first + b.second;
        return x < y;
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<pair<int, int> > hp;
        make_heap(hp.begin(), hp.end(), cmp);
        
        for (int i = 0; i < n1; i++) {
            if (hp.size() >= k && nums1[i] + nums2[0] >= hp.front().first + hp.front().second) break;
            
            for (int j = 0; j < n2; j++) {
                pair<int, int> p = make_pair(nums1[i], nums2[j]);
                
                if (hp.size() < k) {
                    hp.push_back(p); push_heap(hp.begin(), hp.end(), cmp);
                }
                else if (p.first + p.second < hp.front().first + hp.front().second) {
                    pop_heap(hp.begin(), hp.end(), cmp); hp.pop_back();
                    hp.push_back(p); push_heap(hp.begin(), hp.end(), cmp);
                }
                else break;
            }
        }
        
        vector<vector<int> > res;
        for (auto& v : hp) res.push_back({v.first, v.second});
        return res;
    }
};
