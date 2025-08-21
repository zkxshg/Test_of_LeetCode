// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

// binary serach
class Solution {
public:
    bool checkIf(int n, vector<int>& quan, int aim) {
        bool res = true;
        for (int q : quan) {
            n -= ceil((double)q / aim);
            if (n < 0) {
                res = false; break;
            }
        }
        return res;
    }
        
    int minimizedMaximum(int n, vector<int>& quantities) {
        if (n < 2) return quantities[0];
        
        int m = quantities.size();
        
        double low = 0; int maxV = 0; 
        for (int q : quantities) {
          low += (double)q / n;  maxV = max(maxV, q);
        }
        
        int lb = ceil(low), ub = maxV;
        
        int st = lb, en = ub; 
        if (st == en) return st;
        
        while (st < en) {
            int mid = (st + en) / 2;
            if (checkIf(n, quantities, mid)) en = mid;
            else st = mid + 1;
        }
       
        return en;
    }
};

// heap
class Solution {
public:
    bool checkIf()
    int minimizedMaximum(int n, vector<int>& quantities) {
        if (n < 2) return quantities[0];
        
        int m = quantities.size();
        
        vector<pair<int, int> > hp;
        for (int i : quantities) hp.push_back(make_pair(i, i));
        make_heap(hp.begin(), hp.end()); 
        
        if (m == n) return hp.front().first;
        
        n -= m;
        while (n) {
            if (hp.front().first < 10) cout << hp.front().first << ":" << hp.front().second << endl; 
            
            pair<int, int> maxV = hp.front();
            
            pop_heap(hp.begin(), hp.end()); 
            hp.pop_back();
            
            int mul = maxV.second / maxV.first;
            
            mul++;
            
            int temV = maxV.second / mul;
            
            hp.push_back(make_pair(temV, maxV.second));
            push_heap(hp.begin(), hp.end()); 
            
            n--;
            
            
        }
        
        pair<int, int> resV = hp.front();
        
        if (resV.second % resV.first) return resV.first + 1;
        
        return resV.first;
    }
};
