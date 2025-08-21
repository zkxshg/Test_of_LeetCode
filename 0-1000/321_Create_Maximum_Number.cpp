// https://leetcode.com/problems/create-maximum-number/
// stack
class Solution {
public:
    
    vector<int> merge(vector<int>& N1, vector<int>& N2) {
        int m = N1.size(), n = N2.size();
        
        vector<int> res;
        
        int st1 = 0, st2 = 0;
        while (st1 < m || st2 < n) {
            if (st1 >= m) {
                res.push_back(N2[st2]); st2++;
            }
            else if (st2 >= n) {
                res.push_back(N1[st1]); st1++;
            }
            else {
                if (N1[st1] > N2[st2]) {
                    res.push_back(N1[st1]); st1++;
                }
                else if (N1[st1] < N2[st2]) {
                    res.push_back(N2[st2]); st2++;
                }
                else {
                    vector<int> subs1(N1.begin() + st1, N1.end());
                    vector<int> subs2(N2.begin() + st2, N2.end());
                    
                    if (subs1 > subs2) {
                        res.push_back(N1[st1]); st1++;
                    }
                    else {
                       res.push_back(N2[st2]); st2++; 
                    }
                }
            }
        }
        
        return  res;
    }
    
    vector<int> maxI(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n == k) return nums;
        if (k <= 0) return {};
        
        vector<int> st; st.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= st.back()) {
                if (st.size() < k) st.push_back(nums[i]);
            }
            else {
                while (!st.empty() && nums[i] > st.back() && st.size() - 1 + (n - i) >= k) st.pop_back();
                st.push_back(nums[i]);
            }      
        }
        
        return st;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        
        vector<int> res;
        
        for (int i = 0; i <= k; i++) {
            if (m < i) break;
            if (n < k - i) continue;
            
            vector<int> tm = maxI(nums1, i);
            vector<int> tn = maxI(nums2, k - i);
            
            if (res.empty()) res = merge(tm, tn);
            else res = max(res, merge(tm, tn));
        }
        
        return res;
    }
};

// backtracking
class Solution {
public:
    int nexMax(vector<int>& arr, int st, int cost) {
        if (st >= arr.size()) {
            // cout << "st > m !" << endl; 
            return -1;
        }
        
        if (cost <= 0) return st;
        
        int maxV = arr[st], maxPos = st, pos = st;
        
        while (cost >= 0 && pos < arr.size()) {
            if (arr[pos] > maxV) {
                maxV = arr[pos]; maxPos = pos;
            }
            pos++; cost--;
        }
        
        // cout << maxPos << endl;
        return maxPos;
    }
    
    pair<int, int> whichNum(vector<int>& N1, vector<int>& N2, int st1, int st2, int cost) {
        // st1 >= n || st2 >= m
        if (st1 >= N1.size()) return make_pair(2, nexMax(N2, st2, cost));
        
        if (st2 >= N2.size()) return make_pair(1, nexMax(N1, st1, cost));
        // cout << st1 << "," << st2 << endl;
        
        // cost <= 0
        if (cost <= 0) {
            if (N1[st1] > N2[st2]) return make_pair(1, st1);
            if (N1[st1] < N2[st2]) return make_pair(2, st2);
            
            vector<int> subs1(N1.begin() + st1, N1.end());
            vector<int> subs2(N2.begin() + st2, N2.end());
            
            if (subs1 > subs2) return make_pair(1, st1);
            return make_pair(2, st2);
        }
        
        // cost > 0
        int p1 = nexMax(N1, st1, cost); int v1 = N1[p1], c1 = cost - (p1 - st1);
        int p2 = nexMax(N2, st2, cost); int v2 = N2[p2], c2 = cost - (p2 - st2);
        // cout << v1 << "," << v2 << endl;
        
        // v1 == v2
        if (v1 == v2) {
            auto nex1 = whichNum(N1, N2, p1 + 1, st2, c1); 
            v1 = (nex1.first == 1) ? N1[nex1.second] : N2[nex1.second];
        
            auto nex2 = whichNum(N1, N2, st1, p2 + 1, c2); 
            v2 = (nex2.first == 1) ? N1[nex2.second] : N2[nex2.second];
        }
        // cout << st1 << "-" << v1 << "," << st2 << "-" << v2 << endl;
        if (v1 > v2) return make_pair(1, p1);
        if (v1 < v2) return make_pair(2, p2);
        
        return  make_pair(2, p2);
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        
        int cost = m + n - k; // cout << "cost = " << cost << endl;
        
        vector<int> res;
        
        int st1 = 0, st2 = 0;
        while (res.size() < k) {
            auto P = whichNum(nums1, nums2, st1, st2, cost);
            
            if (P.first == 1) {
                res.push_back(nums1[P.second]);
                cost -= (P.second - st1);
                st1 = P.second + 1;
            }
            else {
                res.push_back(nums2[P.second]);
                cost -= (P.second - st2);
                st2 = P.second + 1;
            }
            cout << P.first << ":" << P.second << "=" << res.back() << "<-" << cost << endl;
            // cout << res.back() << endl;
        }
        
        return res;
    }
};
