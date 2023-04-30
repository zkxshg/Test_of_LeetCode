// https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// binary search
class Solution {
public:
    int checkDist(vector<int>& nums, int mid) {
        int res = 0, n = nums.size(), pos = 0, ub = 0, preLb = -1;
        
        while (pos < n && ub < n) {
            int ub = upper_bound(nums.begin(), nums.end(), nums[pos] + mid) - nums.begin();
            
            int lb = ub - 1;
            res += (lb - pos) * (lb - pos + 1) / 2;
            if (preLb >= 0) res -= (preLb - pos) * (preLb - pos + 1) / 2;
            
            preLb = lb; pos++;
        }
        
        return res;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int st = 0, en = nums[n - 1] - nums[0], mid = (st + en) / 2;
        
        while (st < en) {
            mid = (st + en) / 2;
            
            int less = checkDist(nums, mid);
            
            if (less >= k) {
                if (checkDist(nums, mid - 1) < k) return mid;
                else en = mid; 
            }
            else st = mid + 1;
        }
        return st;
    }
};

// binary search + heap
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> kheap;  // store the k-num smallest dist
        make_heap(kheap.begin(), kheap.end());
        
        vector<int> suf;    // store the visited suffix of array
        suf.push_back(nums[n - 1]);
        
        for (int i = n - 2; i >= 0; i--) {
            int pos = lower_bound(suf.begin(), suf.end(), nums[i]) - suf.begin();
            
            int val = nums[i], pre = pos - 1, nex = pos;
            
            while (pre >= 0) {
                int dist = abs(suf[pre] - nums[i]);
                
                if (kheap.size() < k) {
                    kheap.push_back(dist); 
                    if (kheap.size() == k) make_heap(kheap.begin(), kheap.end());
                }
                
                else if (kheap.front() > dist) {
                    pop_heap(kheap.begin(), kheap.end()); kheap.pop_back();
                    kheap.push_back(dist); push_heap(kheap.begin(), kheap.end());
                }
                else break;
                
                pre--;
            }
            
            while (nex < suf.size()) {
                int dist = abs(suf[nex] - nums[i]);
                
                if (kheap.size() < k) {
                    kheap.push_back(dist); 
                    if (kheap.size() == k) make_heap(kheap.begin(), kheap.end());
                }
                else if (kheap.front() > dist) {
                    pop_heap(kheap.begin(), kheap.end()); kheap.pop_back();
                    kheap.push_back(dist); push_heap(kheap.begin(), kheap.end());
                }
                else break;
                
                nex++;
            }
            
            suf.insert(suf.begin() + pos, val);
        }
        
        return kheap.front();
    }
};
