// 3479. Fruits Into Baskets III
// Link: https://leetcode.com/problems/fruits-into-baskets-iii/
// Lang: C++
// Date: 2025-08-21 20:51:59.240 UTC

class SegmentTree {
public:
    SegmentTree(const vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    // Find the first index >= 0 where capacity >= val, or -1 if none exists
    int findFirst(int node, int l, int r, long long val) {
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (tree[node << 1] >= val)
            return findFirst(node << 1, l, mid, val);
        else
            return findFirst(node << 1 | 1, mid + 1, r, val);
    }

    // Update the capacity at position idx to newVal
    void update(int node, int l, int r, int idx, long long newVal) {
        if (l == r) {
            tree[node] = newVal;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            update(node << 1, l, mid, idx, newVal);
        else
            update(node << 1 | 1, mid + 1, r, idx, newVal);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

private:
    int n;
    vector<long long> tree;

    void build(int node, int l, int r, const vector<long long>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, arr);
        build(node << 1 | 1, mid + 1, r, arr);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int n = fruits.size();
        // Build segment tree over basket capacities
        vector<long long> caps(baskets.begin(), baskets.end());
        SegmentTree st(caps);

        int unplaced = 0;
        // Place each fruit in order
        for (int f : fruits) {
            int idx = st.findFirst(1, 0, n - 1, f);
            if (idx == -1) {
                // No available basket can hold this fruit
                unplaced++;
            } else {
                // Mark this basket as used by setting its capacity to 0
                st.update(1, 0, n - 1, idx, 0);
            }
        }
        return unplaced;

    }
};
