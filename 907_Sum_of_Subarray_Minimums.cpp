// https://leetcode.com/problems/sum-of-subarray-minimums/
// DP + stack

class Solution {
public:
    #define ll long long
    ll ub = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return arr[0];
        
        vector<ll> res(n); res[0] = arr[0]; 
        
        vector<int> st; st.push_back(0);
        
        for (int i = 1; i < n; i++) {
            while (!st.empty()) {
                if (arr[st.back()] >= arr[i]) st.pop_back(); 
                else break;
            }
            
            if (st.empty()) res[i] = (i + 1) * arr[i] % ub;
            else res[i] = ((i - st.back()) * arr[i] + res[st.back()]) % ub;
            
            st.push_back(i);
        }
        
        ll sum = 0;
        for (int i : res) sum = (sum + i) % ub;
        return sum;
    }
};
