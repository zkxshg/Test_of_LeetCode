// 3480. Maximize Subarrays After Removing One Conflicting Pair
// Link: https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/
// Lang: C++
// Date: 2025-08-21 20:54:16.579 UTC

class Solution {
public:
    #define ll long long

     long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        // 1) Normalize pairs so a<b and bucket by right endpoint b
        vector<vector<int>> byRight(n + 1);
        for (auto &p : conflictingPairs) {
            int a = p[0], b = p[1];
            if (a == b) continue;
            if (a > b) std::swap(a, b);
            byRight[b].push_back(a);
        }

        // 2) For each right endpoint b, compute:
        //    best[b]  = max a for this b
        //    cntBest[b] = frequency of the max a
        //    second[b] = second maximum a (0 if none)
        vector<int> best(n + 1, 0), second(n + 1, 0), cntBest(n + 1, 0);
        for (int b = 1; b <= n; ++b) {
            int t1 = 0, t2 = 0, c1 = 0;
            for (int a : byRight[b]) {
                if (a > t1) { t2 = t1; t1 = a; c1 = 1; }
                else if (a == t1) { c1++; }
                else if (a > t2) { t2 = a; }
            }
            best[b] = t1;
            second[b] = t2;
            cntBest[b] = c1;
        }

        // 3) Build base[] = best[], pref[] = running max over base[]
        vector<int> base(n + 1, 0), pref(n + 1, 0);
        for (int i = 1; i <= n; ++i) base[i] = best[i];

        ll sumPref = 0;
        for (int i = 1; i <= n; ++i) {
            pref[i] = std::max(pref[i - 1], base[i]);
            sumPref += pref[i];
        }

        // 4) Next greater-or-equal to the right for base[]
        //    nxt[i] = smallest j>i with base[j] >= base[i], or n+1 if none
        vector<int> nxt(n + 2, n + 1);
        vector<int> st;
        st.reserve(n);
        for (int i = n; i >= 1; --i) {
            while (!st.empty() && base[st.back()] < base[i]) st.pop_back();
            nxt[i] = st.empty() ? (n + 1) : st.back();
            st.push_back(i);
        }

        // 5) Evaluate the best improvement by removing exactly one pair
        //    Only indices i where base[i] > pref[i-1] (a strict new record)
        //    and the top 'a' at i is unique (cntBest[i] == 1) can change anything.
        ll bestGain = 0;

        for (int i = 1; i <= n; ++i) {
            if (base[i] == 0) continue;               // no pair ends at i
            if (base[i] <= pref[i - 1]) continue;     // not a strict record
            if (cntBest[i] != 1) continue;            // removing one doesn't lower best[i]

            int a = base[i];
            int L = i;
            int R = nxt[i] - 1;                       // inclusive segment where pref[r] == a
            int floor0 = std::max(pref[i - 1], second[i]);

            // Old sum over this plateau:
            ll oldSum = 1LL * (R - L + 1) * a;

            // New sum after removing this (a, i): start at r=L with floor0,
            // then scan [L+1..R] accumulating running max vs base[]
            ll newSum = floor0;           // r = L
            int cur = floor0;
            for (int j = L + 1; j <= R; ++j) {
                cur = std::max(cur, base[j]);
                newSum += cur;
            }

            bestGain = std::max(bestGain, oldSum - newSum);
        }

        // 6) Base valid subarrays and add best gain
        ll total = 1LL * n * (n + 1) / 2;
        ll baseValid = total - sumPref;
        return baseValid + bestGain;
    }
};
