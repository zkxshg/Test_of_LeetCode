// quick union
class Solution {
public:
    unordered_map<int, int> p;
    
    int find(int a) {
        if (!p.count(a)) return p[a] = a;
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }
    
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        for (int a : A)
            p[a] = a;
        for (int a : A) 
            for (int i = 2; i <= sqrt(a); ++i)
                if (a % i == 0) {
                    p[find(a)] = p[find(i)];
                    p[find(a)] = p[find(a / i)];
                }
        unordered_map<int, int> cnt;
        int res = 1;
        for (int a : A)
            res = max(res, ++cnt[find(a)]);
        return res;
    }
};

// quick find
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int len = A.size();
        if (len < 2) return len;
        
        sort(A.begin(), A.end());
        
        vector<int> id(len);
        vector<int> count(len, 1);
        for (int i = 0 ; i < len; i++) id[i] = i;
         
        for (int i = 0; i < len; i++) {
            int j = i + 1;
            while (j < len){
                if (id[j] != id[i]  && find(A[i], A[j])) {
                    if (id[j] != j) {
                        //for (int k = i + 1; k < j; k++) {
                        //    if (id[k] == id[i]) id[k] = id[j];  
                        //} 
                        count[id[j]] += count[id[i]];
                        count[id[i]] = 0;
                        id[i] = id[j];
                    }
                    else {
                        count[id[j]]--;
                        id[j] = id[i];
                        count[id[i]]++;
                    }   
                }
                j++;
            }
        }

        return *max_element(count.begin(), count.end());
    }
    
    bool find(int p, int q) {
        if (p == 1 && q == 1) return false;
        
        int t = 1;
        while(t > 0) {
            t = p % q;
            p = q;
            q = t; 
        }
        if (p == 1) return false;
        return true;
    }
    
    bool find2(int p, int q) {
        int UB = min(p, q);
        for (int i = 2; i <= UB; i++) {
            if (p % i == 0 && q % i == 0) return true;
        }
        return false;
    }
};
