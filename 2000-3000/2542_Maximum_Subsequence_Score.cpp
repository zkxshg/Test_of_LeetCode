// https://leetcode.com/problems/maximum-subsequence-score/description/
// soring + heap + greedy

class Solution {
public:
    #define ll long long
    #define pii pair<int, int>

    static bool cmp(pii& a, pii& b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }

    static bool cmp2(int a, int b) {
        return a > b;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();   

        vector<pii> np;
        for (int i = 0; i < n; i++) np.push_back({nums1[i], nums2[i]});
        sort(np.begin(), np.end(), cmp);

        vector<int> hp; ll s1 = 0; int s2 = np[k - 1].second;
        for(int i = 0; i < k; i++) {
            hp.push_back(np[i].first); s1 += np[i].first;
        }

        make_heap(hp.begin(), hp.end(), cmp2);

        ll res = s1 * s2;
        
        for (int i = k; i < n; i++) {
            int n1 = hp.front(), nn1 = np[i].first; 
            s2 = min(s2, np[i].second);

            ll ns1 = s1 - n1 + nn1;

            if (n1 < nn1) {
                pop_heap(hp.begin(), hp.end(), cmp2); hp.pop_back();
                hp.push_back(nn1); push_heap(hp.begin(), hp.end(), cmp2);

                s1 = ns1;
            }

            res = max(res, s1 * s2);
        }

        return res;
    }
};
