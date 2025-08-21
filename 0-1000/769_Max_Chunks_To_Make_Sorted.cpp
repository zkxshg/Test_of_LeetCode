// https://leetcode.com/problems/max-chunks-to-make-sorted/
// permutation + greedy

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), res = 0, pos = 0;
        
        vector<int> pmt(n);
        for (int i = 0; i < n; i++) pmt[arr[i]] = i;
        // for (int i = 0; i < n; i++) cout << pmt[i] << ","; cout << endl;
        
        while (pos < n) {
            int ub = pmt[pos];
            
            while (pos < ub) {
                pos++;
                ub = max(ub, pmt[pos]); 
            }
            
            res++; pos++;
        }
        
        return res;
    }
};
