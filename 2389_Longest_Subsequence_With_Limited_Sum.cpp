// https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
// sorting + greedy

class Solution {
public:
    #define N nums
    #define Q queries

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = N.size(), m = Q.size();
        
        sort(N.begin(), N.end());
        vector<int> pre(n); pre[0] = N[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + N[i];

        //for (int i = 0; i < n; i++) cout << pre[i] << ","; cout << endl;
        vector<int> res(m);
        for (int i = 0; i < m; i++) 
            res[i] = upper_bound(pre.begin(), pre.end(), Q[i]) - pre.begin();
        
        return res;
    }

    vector<int> answerQueriesOfSubstring(vector<int>& nums, vector<int>& queries) {
        int n = N.size(), m = Q.size();
        
        vector<int> ps(n); ps[0] = N[0];
        for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + N[i];

        vector<int> pre(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            int pi = (i > 0) ? ps[i - 1] : 0;
            for (int j = i; j < n; j++)  pre[j - i] = min(pre[j - i], ps[j] - pi);
        }

        for (int i = 0; i < n; i++) cout << pre[i] << ","; cout << endl;

        vector<int> res(m);
        for (int i = 0; i < m; i++) 
            res[i] = upper_bound(pre.begin(), pre.end(), Q[i]) - pre.begin();
        
        return res;
    }
};
