// https://leetcode.com/problems/k-th-smallest-prime-fraction/
// heap

class Solution {
public:
    #define ll long long
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        ll a0 = a.first, a1 = a.second, b0 = b.first, b1 = b.second;
        return a0 * b1 < a1 * b0;
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<pair<int, int>> hp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pair<int, int> p = {arr[i], arr[j]};

                if (hp.size() < k) {
                    hp.push_back(p);
                    
                    if (hp.size() == k) make_heap(hp.begin(), hp.end(), cmp);
                }
                else {
                    hp.push_back(p); push_heap(hp.begin(), hp.end(), cmp);
                    
                    pop_heap(hp.begin(), hp.end(), cmp); hp.pop_back();
                }
            }
        }
        
        auto kth = hp.front();
        return {kth.first, kth.second};
    }
};
