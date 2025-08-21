// two pointers
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        
        int len = nums.size();
        if (len < 2) return false;
        
        vector<pair<int, int>> dict;
        
        for(int i = 0; i < len; i++) dict.push_back(make_pair(nums[i], i));
        sort(dict.begin(), dict.end());
        
        int p1 = 0, p2 = 1;
        
        while (p2 < len) {
            
            long long int f1 = dict[p1].first, f2 = dict[p2].first;
            int s1 = dict[p1].second, s2 = dict[p2].second;
            
            if (abs(s1 - s2) <= k && abs(f1 - f2) <= t) return true;
            
            if (abs(s1 - s2) > k) p2++;
            
            if (abs(f1 - f2) > t) p1++;
            
            if (p1 == p2) p2++;
        }
        
        return false;
    }

};

// sliding window
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        
        int len = nums.size();
        if (len < 2) return false;
        
        
        vector<int> kSet; kSet.push_back(nums[0]);
        
        for (int i = 1; i < k; i++) {
            if (ifClose(kSet, nums[i], t)) return true;
            kSet.insert(lower_bound(kSet.begin(), kSet.end(), nums[i]), nums[i]);
        }

        for (int i = k; i < len; i++) {
            if (ifClose(kSet, nums[i], t)) return true;
            kSet.erase(find(kSet.begin(), kSet.end(), nums[i - k]));
            kSet.insert(lower_bound(kSet.begin(), kSet.end(), nums[i]), nums[i]);
        }
        
        return false;
    }
    
    bool ifClose(vector<int> A, int a1, int t) {
        double a = a1; 
        auto pos = lower_bound(A.begin(), A.end(), a1);
        
        if (pos - A.end() == 0) {
            if (a - A.back() <= t) return true;
            else return false;
        } 
        
        if (pos - A.begin() == 0){
            if (A[0] - a <= t) return true;
            else return false;
        } 
        
        if (A[pos - A.begin()] - a <= t || a - A[pos - A.begin() - 1] <= t) return true;
        return false;
    }
};
