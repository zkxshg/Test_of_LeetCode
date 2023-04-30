// https://leetcode.com/problems/count-of-range-sum/
// prefix sum + segment tree

class Solution {
public:
    #define ll long long
    
    int res, up, low;
    
    vector<ll> tree;
    
    int get_mid(int a, int b) {
        return a + (b - a) / 2;
    }
    
    ll query(int index, int s, int e, int qs, int qe) {
        if (s >= qs and e <= qe) return tree[index];

        if (e < qs or s > qe) return 0;

        int mid = get_mid(s, e);

        ll leftAns = query(2 * index + 1, s, mid, qs, qe);
        ll rightAns = query(2 * index + 2, mid + 1, e, qs, qe);

        return leftAns + rightAns;
    }
    
    void update(int index, int s, int e, int pos, int val) {

        if (s == e) {
            tree[index] = val; return;
        }

        int mid = get_mid(s, e);

        if (pos <= mid) update(2 * index + 1, s, mid, pos, val);
        else update(2 * index + 2, mid + 1, e, pos, val);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        tree.resize(4 * n + 1);
        
        // pre-sum
        set<ll> preSet; ll preS = 0;
        for (int i = 0; i < n; i++) {
            preS += nums[i]; preSet.insert(preS);
        }
        
        vector<ll> preV;
        preV.assign(preSet.begin(), preSet.end());
        //  for (int i : preV) cout << i << ","; cout << endl;
        
        // segment tree
        preS = 0; int res = 0, len = preV.size();
        for (int i = 0; i < n; i++) {
            preS += nums[i];
            if (preS <= upper && preS >= lower) res++;
            
            int lb = lower_bound(preV.begin(), preV.end(), preS - upper) - preV.begin();
            int rb = upper_bound(preV.begin(), preV.end(), preS - lower) - preV.begin();
            
            res += query(0, 0, len - 1, lb, rb - 1);
            // cout << i << "-" << res << endl;
            int pos = lower_bound(preV.begin(), preV.end(), preS) - preV.begin();
            update(0, 0, len - 1, pos, 1 + query(0, 0, len - 1, pos, pos));                
        }

        
        return res;
    }
};

// segment tree
class Solution {
public:
    #define ll long long
    
    ll tree[262145];
    
    int get_mid(int a, int b) {
        return a + (b - a) / 2;
    }
    
    ll query(int index, int s, int e, int qs, int qe) {
        if (s >= qs and e <= qe) return tree[index];

        if (e < qs or s > qe) return 0;

        int mid = get_mid(s, e);

        ll leftAns = query(2 * index + 1, s, mid, qs, qe);
        ll rightAns = query(2 * index + 2, mid + 1, e, qs, qe);

        return leftAns + rightAns;
    }
    
    void dfs(int index, int s, int e) {
        // if (tree[index] <= up && tree[index] >= low) res++; 
        
        if (s == e) return;

        int mid = get_mid(s, e);

        dfs(2 * index + 1, s, mid);
        dfs(2 * index + 2, mid + 1, e);
    }
    
    void update(int index, int s, int e, int pos, int val) {

        if (s == e) {
            tree[index] = val; return;
        }

        int mid = get_mid(s, e);

        if (pos <= mid) update(2 * index + 1, s, mid, pos, val);
        else update(2 * index + 2, mid + 1, e, pos, val);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) update(0, 0, n - 1, i, nums[i]);
        
        int res = 0;
        
        // dfs(0, 0, n - 1);
        
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++) {
                ll q = query(0, 0, n - 1, i, j);
                if (q <= upper && q >= lower) res++;
            }
        
        return res;
    }
};
