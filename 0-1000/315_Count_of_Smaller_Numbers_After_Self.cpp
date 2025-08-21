// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// segment tree

class Solution {
public:
    int tree[262145];

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
    
    void update(int index, int s, int e, int pos) {

        if (s == e) {
            tree[index]++; return;
        }

        int mid = get_mid(s, e);

        if (pos <= mid) update(2 * index + 1, s, mid, pos);
        else update(2 * index + 2, mid + 1, e, pos);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int m = nums.size();
        
        long long cost = 0, n = 1e5 + 1, bias = 1e4;
        
        vector<int> res;
        for (int i = m - 1; i >= 0; i--) {
            int x = nums[i]; x += bias;
            
            int less = query(0, 0, n, 0, x - 1);
            res.push_back(less);

            update(0, 0, n, x);
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};

// sort
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sn; sn.push_back(INT_MIN);
        
        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
            int pos =  lower_bound(sn.begin(), sn.end(), nums[i]) - sn.begin();
            
            if (pos == 0) res.push_back(0);
            else res.push_back(pos - 1);
            
            sn.insert(sn.begin() + pos, nums[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};
