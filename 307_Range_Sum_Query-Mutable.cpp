// https://leetcode.com/problems/range-sum-query-mutable/
// segment tree

class NumArray {
public:
    vector<int> tree;
    
    int get_mid(int a, int b) {
        return a + (b - a) / 2;
    }
    
    int query(int index, int s, int e, int qs, int qe) {
        if (s >= qs and e <= qe) return tree[index];

        if (e < qs or s > qe) return 0;

        int mid = get_mid(s, e);

        int leftAns = query(2 * index + 1, s, mid, qs, qe);
        int rightAns = query(2 * index + 2, mid + 1, e, qs, qe);

        return leftAns + rightAns;
    }
    
    void update(int index, int s, int e, int pos, int val) {

        if (s == e) { tree[index] = val; return;}

        int mid = get_mid(s, e);

        if (pos <= mid) update(2 * index + 1, s,       mid, pos, val);
        else            update(2 * index + 2, mid + 1, e,   pos, val);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    void createSortedArray(vector<int>& nums) {
        long long n = 1e5 + 1, len = nums.size();
        for (int i = 0; i < len; i++) update(0, 0, n, i, nums[i]);
    }
    
    NumArray(vector<int>& nums) {
        tree.clear(); tree.resize(262145);
        createSortedArray(nums);
    }
    
    void update(int index, int val) {
        long long n = 1e5 + 1;
        update(0, 0, n, index, val);
    }
    
    int sumRange(int left, int right) {
        long long n = 1e5 + 1;
        return query(0, 0, n, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
