// https://leetcode.com/problemset/all/?search=1649
// segment tree
class Solution {
public:
    #define ins instructions
    
    int tree[262145];
    
    int createSortedArray(vector<int>& instructions) {
        long long cost = 0, n = 1e5 + 1, up = 1e9 + 7;
        
        
        for(int x : instructions) {
            int less = query(0, 0, n, 0, x - 1); 
			
            int great = query(0, 0, n, x + 1, n); 
            
            update(0, 0, n, x);
            
            cost = (cost + min(less, great)) % up;
        }
        
        return cost; 
    }
    
    int get_mid(int a, int b) {
        return a + (b - a)/2;
    }
    
    int query(int index, int s, int e, int qs, int qe) {
        if(s >= qs and e <= qe) return tree[index];
        
        if(e < qs or s > qe) return 0;
        
        int mid = get_mid(s, e);
        
        int leftAns = query(2*index + 1, s, mid, qs, qe);
        int rightAns = query(2*index + 2, mid + 1, e, qs, qe);
        
        return leftAns + rightAns;
    }
    
    void update(int index, int s, int e, int pos) {
        
        if(s == e) {
            tree[index]++; return;
        } 
		
        int mid = get_mid(s, e);
            
		if(pos <= mid) update(2*index + 1, s, mid, pos);
		else update(2*index + 2, mid + 1, e, pos);

		tree[index] = tree[2*index + 1] + tree[2*index + 2];
    }
};

// invertion seearch
class Solution {
public:
    #define ins instructions
    int createSortedArray(vector<int>& instructions) {
        long long cost = 0, len = ins.size(), up = pow(10, 9) + 7;
        unordered_map<int, int> fre;
        
        for (int i = 0; i < len; i++) {
            int j = i, aim = ins[i];
            while (j > 0 && ins[j - 1] > aim) {
                ins[j] = ins[j - 1]; j -= fre[ins[j]];
            }
            ins[j] = aim;
            
            cost += min(j - fre[aim], i - j); cost %= up;
            fre[aim]++;
        }
        return cost;
    }
};
